--
-- @file        CUTS-baseline.sql
--
-- $Id$
--
-- @author      James H. Hill
--

USE cuts;

--
-- Create the baseline table. This table contains baseline
-- metric information to each component instance type,
-- per host.
--

CREATE TABLE IF NOT EXISTS baseline
(
  bid             INT             NOT NULL auto_increment,
  instance        INT             NOT NULL,
  host            INT             NOT NULL DEFAULT 0,
  inport          INT             NOT NULL,
  outport         INT             NOT NULL,
  event_count     INT,
  best_time       INT,
  worst_time      INT,
  total_time      INT,

  -- set the primary key
  PRIMARY KEY (bid),

  -- set the unique keys
  UNIQUE (instance, host, inport, outport),

  -- set the foreign key(s)
  FOREIGN KEY (instance) REFERENCES component_instances (component_id)
    ON DELETE RESTRICT
    ON UPDATE CASCADE,

  FOREIGN KEY (host) REFERENCES ipaddr_host_map (hostid)
    ON DELETE RESTRICT
    ON UPDATE CASCADE,

  FOREIGN KEY (inport) REFERENCES ports (pid)
    ON DELETE RESTRICT
    ON UPDATE CASCADE,

  FOREIGN KEY (outport) REFERENCES ports (pid)
    ON DELETE RESTRICT
    ON UPDATE CASCADE
);

DELIMITER //

-------------------------------------------------------------------------------
-- PROCEDURE: cuts.insert_component_baseline_using_ipaddr
-------------------------------------------------------------------------------

DROP PROCEDURE IF EXISTS cuts.insert_component_baseline_using_ipaddr //

CREATE PROCEDURE
  cuts.insert_component_baseline_using_ipaddr (
    IN inst VARCHAR (255),
    IN ip_addr VARCHAR (40),
    IN inport VARCHAR (255),
    IN outport VARCHAR (255),
    IN ec INT,
    IN bt INT,
    IN wt INT,
    IN tt INT)
BEGIN
  DECLARE tid INT;
  DECLARE cid INT;
  DECLARE hid INT;

  -- get the type id of the component
  SELECT typeid INTO tid FROM component_instances
    WHERE component_name = inst LIMIT 1;

  -- get the id of the sender and current component
  SELECT component_id INTO cid FROM component_instances
    WHERE component_name = inst;

  SELECT hostid INTO hid FROM ipaddr_host_map
    WHERE ipaddr = ip_addr;

  INSERT INTO cuts.baseline (instance, host, inport, outport,
    event_count, best_time, worst_time, total_time)
    VALUES (cid, hid,
     (SELECT pid FROM ports WHERE ctype = tid AND
          portid = (SELECT portid FROM portnames WHERE portname = inport) AND
          port_type = 'sink'),
     (SELECT pid FROM ports WHERE ctype = tid AND
          portid = (SELECT portid FROM portnames WHERE portname = outport) AND
          port_type = 'source'),
     ec, bt, wt, tt);

END; //

-------------------------------------------------------------------------------
-- PROCEDURE: cuts.insert_component_baseline_using_hostname
-------------------------------------------------------------------------------

DROP PROCEDURE IF EXISTS cuts.insert_component_baseline_using_hostname //

CREATE PROCEDURE
  cuts.insert_component_baseline_using_hostname (
    IN inst VARCHAR (255),
    IN host VARCHAR (40),
    IN inport VARCHAR (255),
    IN outport VARCHAR (255),
    IN ec INT,
    IN bt INT,
    IN wt INT,
    IN tt INT)
BEGIN
  DECLARE tid INT;
  DECLARE cid INT;
  DECLARE hid INT;

  -- get the type id of the component
  SELECT typeid INTO tid FROM component_instances
    WHERE component_name = inst LIMIT 1;

  -- get the id of the sender and current component
  SELECT component_id INTO cid FROM component_instances
    WHERE component_name = inst;

  SELECT hostid INTO hid FROM ipaddr_host_map
    WHERE hostname = host;

  INSERT INTO cuts.baseline (instance, host, inport, outport,
    event_count, best_time, worst_time, total_time)
    VALUES (cid, hid,
     (SELECT pid FROM ports WHERE ctype = tid AND
          portid = (SELECT portid FROM portnames WHERE portname = inport) AND
          port_type = 'sink'),
     (SELECT pid FROM ports WHERE ctype = tid AND
          portid = (SELECT portid FROM portnames WHERE portname = outport) AND
          port_type = 'source'),
     ec, bt, wt, tt);

END; //

DELIMITER ;
