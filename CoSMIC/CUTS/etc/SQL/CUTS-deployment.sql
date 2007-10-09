--
-- @file        CUTS-deployment.sql
--
-- $Id: CUTS-baseline.sql 1114 2007-02-01 23:55:29Z hillj $
--
-- @author      James H. Hill
--

USE cuts;

--
-- Create the 'deployment' table. This table contains the location
-- uptime and downtime of a component instance per test.
--

CREATE TABLE IF NOT EXISTS deployment
(
  deploy_id         INT         NOT NULL auto_increment,
  test_number       INT         NOT NULL,
  instance          INT         NOT NULL,
  hostid            INT         NOT NULL,
  uptime            DATETIME,
  downtime          DATETIME,

  PRIMARY KEY (deploy_id),
  FOREIGN KEY (test_number) REFERENCES tests (test_number)
    ON DELETE CASCADE,
  FOREIGN KEY (instance) REFERENCES component_instances (component_id)
    ON DELETE RESTRICT
    ON UPDATE CASCADE,
  FOREIGN KEY (hostid) REFERENCES ipaddr_host_map (hostid)
    ON DELETE RESTRICT
    ON UPDATE CASCADE
);

DELIMITER //

-------------------------------------------------------------------------------
-- PROCEDURE: cuts.set_component_uptime
-------------------------------------------------------------------------------

DROP PROCEDURE IF EXISTS cuts.set_component_uptime //

CREATE PROCEDURE
  cuts.set_component_uptime (IN test INT,
                             IN instance_name VARCHAR(255),
                             IN host INT)
BEGIN
  DECLARE inst_id INT;

  SELECT component_id INTO inst_id
    FROM component_instances WHERE component_name = instance_name;

  INSERT INTO cuts.deployment (test_number, instance, hostid, uptime)
    VALUES (test, inst_id, host, NOW());
END; //

-------------------------------------------------------------------------------
-- PROCEDURE: cuts.set_component_uptime_using_hostname
-------------------------------------------------------------------------------

DROP PROCEDURE IF EXISTS cuts.set_component_uptime_using_hostname //

CREATE PROCEDURE
  cuts.set_component_uptime_using_hostname (IN test INT,
                                            IN instance_name VARCHAR(255),
                                            IN host VARCHAR(256))
BEGIN
  DECLARE hid INT;

  -- get the hostid for the hostname
  SELECT hostid INTO hid
    FROM ipaddr_host_map WHERE hostname = host;

  CALL set_component_uptime (test, instance_name, hid);
END; //

-------------------------------------------------------------------------------
-- PROCEDURE: cuts.set_component_uptime_using_ipaddr
-------------------------------------------------------------------------------

DROP PROCEDURE IF EXISTS cuts.set_component_uptime_using_ipaddr //

CREATE PROCEDURE
  cuts.set_component_uptime_using_ipaddr (IN test INT,
                                          IN instance_name VARCHAR(255),
                                          IN ip VARCHAR(40))
BEGIN
  DECLARE hid INT;

  -- get the hostid for the ip-address
  SELECT hostid INTO hid
    FROM ipaddr_host_map WHERE ipaddr = ip;

  CALL set_component_uptime (test, instance_name, hid);
END; //

-------------------------------------------------------------------------------
-- PROCEDURE: cuts.set_component_downtime
-------------------------------------------------------------------------------

DROP PROCEDURE IF EXISTS cuts.set_component_downtime //

CREATE PROCEDURE
  cuts.set_component_downtime (IN test INT,
                               IN instance_name VARCHAR(255),
                               IN host INT)
BEGIN
  DECLARE inst_id INT;

  SELECT component_id INTO inst_id
    FROM component_instances WHERE component_name = instance_name;

  UPDATE cuts.deployment SET downtime = NOW()
    WHERE test_number = test AND instance = inst_id AND
      hostid = host AND downtime IS NULL;
END; //


-------------------------------------------------------------------------------
-- PROCEDURE: cuts.set_component_downtime_using_hostname
-------------------------------------------------------------------------------

DROP PROCEDURE IF EXISTS cuts.set_component_downtime_using_hostname //

CREATE PROCEDURE
  cuts.set_component_downtime_using_hostname (IN test INT,
                                              IN instance_name VARCHAR(255),
                                              IN host VARCHAR(256))
BEGIN
  DECLARE hid INT;

  SELECT hostid INTO hid
    FROM ipaddr_host_map WHERE hostname = host;

  CALL set_component_downtime(test, instance_name, hid);
END; //

-------------------------------------------------------------------------------
-- PROCEDURE: cuts.set_component_downtime_using_ipaddr
-------------------------------------------------------------------------------

DROP PROCEDURE IF EXISTS cuts.set_component_downtime_using_ipaddr //

CREATE PROCEDURE
  cuts.set_component_downtime_using_ipaddr (IN test INT,
                                            IN instance_name VARCHAR(255),
                                            IN ip VARCHAR(40))
BEGIN
  DECLARE hid INT;

  SELECT hostid INTO hid
    FROM ipaddr_host_map WHERE ipaddr = ip;

  CALL set_component_downtime(test, instance_name, hid);
END; //

DELIMITER ;
