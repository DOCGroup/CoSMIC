--
-- @file        CUTS-create.sql
--
-- $Id$
--
-- @author      James H. Hill
--

CREATE DATABASE IF NOT EXISTS cuts;
USE cuts;

--
-- Create the test table. This table contains the test
-- registration information to map/manage the information
-- contained in the exeuction_time table correctly.
--

CREATE TABLE IF NOT EXISTS tests
(
  test_number   INT             NOT NULL auto_increment,
  test_name     VARCHAR(255),
  test_uuid     VARCHAR(255),

  start_time    DATETIME,
  stop_time     DATETIME,

  status        ENUM ('inactive',
                      'active',
                      'complete'),

  -- set the contraints for the table
  PRIMARY KEY (test_number)
);

--
-- Create the table that contains all the component types.
-- We also initialize the table after we have created it.
--

CREATE TABLE IF NOT EXISTS component_types
(
  typeid          INT              NOT NULL auto_increment,
  typename        VARCHAR (255)    NOT NULL,
  sinks           VARCHAR (255),
  sources         VARCHAR (255),

  PRIMARY KEY (typeid),
  UNIQUE (typename)
);

--INSERT INTO component_types (typename)
--  VALUES ('Unknown');

--
-- Create the table that contains the names of ports.
--

CREATE TABLE IF NOT EXISTS portnames
(
  portid          INT              NOT NULL auto_increment,
  portname        VARCHAR (255)    default NULL,

  PRIMARY KEY (portid),
  UNIQUE (portname)
);

--INSERT INTO portnames (portid, portname)
--  VALUES (1, 'Unknown');

--
-- Create the ports table. This table contains which ports
-- belong to what component types. It also contains the ports
-- type (i.e., facet, receptacle, & etc.).
--

CREATE TABLE IF NOT EXISTS ports
(
  pid              INT      NOT NULL auto_increment,
  ctype            INT      NOT NULL,
  portid           INT      NOT NULL,
  port_type        ENUM ('sink', 'source', 'facet', 'receptacle') NOT NULL,

  -- set the constaints for the table
  PRIMARY KEY (pid),
  UNIQUE (ctype, portid, port_type),

  FOREIGN KEY (ctype) REFERENCES component_types (typeid)
    ON DELETE RESTRICT
    ON UPDATE CASCADE,
  FOREIGN KEY (portid) REFERENCES portnames (portid)
    ON DELETE RESTRICT
    ON UPDATE CASCADE
);

--
-- This table contains the mapping of UUIDs their appropriate
-- component name. The UUID is the primary key for the table
-- because no two components can have the same UUID regardless
-- of them being located in two totally different deployments,
-- or systems.
--

CREATE TABLE IF NOT EXISTS component_instances
(
  component_id    INT             NOT NULL auto_increment,
  typeid          INT             NOT NULL DEFAULT 0,
  component_name  VARCHAR (512)   default NULL,

  PRIMARY KEY (component_id),
  UNIQUE      (component_name),

  FOREIGN KEY (typeid) REFERENCES component_types (typeid)
    ON DELETE RESTRICT
    ON UPDATE CASCADE
);

--INSERT INTO component_instances (typeid, component_name)
-- VALUES (1, 'Unknown');

--
-- Table the contains the mapping of a IP-address to a
-- readable hostname. The port number contains the port
-- the node daemon is listening. We also initialize the
-- table with some values after we have created it.
--

CREATE TABLE IF NOT EXISTS ipaddr_host_map
(
  hostid      INT               NOT NULL auto_increment,
  ipaddr      VARCHAR (40)      NOT NULL,
  hostname    VARCHAR (255),
  portnum     INT(5)            DEFAULT NULL,

  PRIMARY KEY (hostid),
  UNIQUE (hostname)
);

--INSERT INTO ipaddr_host_map (ipaddr, hostname)
--  VALUES ('0.0.0.0', 'unknown'), ('127.0.0.1', 'localhost');

--
-- Create the scratchpad table. This is the table the
-- database worker uses to perform its database
-- operations for the given workload.
--

CREATE TABLE IF NOT EXISTS scratchpad
(
  component_id    int        NOT NULL,
  worktag         int        NOT NULL,
  dataset         varchar (255)
);

--
-- Create the 'users' table. This table contains login information
-- for users who are allowed to view the database.
--

CREATE TABLE IF NOT EXISTS users
(
  userid          INT             NOT NULL auto_increment,
  username        VARCHAR(50)     NOT NULL,
  password        TINYTEXT        NOT NULL,
  email           VARCHAR(50)     NOT NULL,
  admin           TINYINT(1)      NOT NULL DEFAULT 0,

  PRIMARY KEY (userid),
  UNIQUE (username)
);

--
-- create user 'cuts'
--

GRANT SELECT, UPDATE, DELETE, INSERT, EXECUTE
  ON cuts.*
  TO cuts@'%'
  IDENTIFIED BY 'cuts';

GRANT SELECT, UPDATE, DELETE, INSERT, EXECUTE
  ON cuts.*
  TO cuts@'localhost'
  IDENTIFIED BY 'cuts';

-------------------------------------------------------------------------------
--

DELIMITER //

-------------------------------------------------------------------------------
-- FUNCTION: cuts.component_portname
-------------------------------------------------------------------------------

DROP FUNCTION IF EXISTS cuts.component_portname //

CREATE FUNCTION cuts.component_portname (pid INT)
RETURNS VARCHAR (255)
BEGIN
  DECLARE portname VARCHAR (255);

  SELECT t2.portname INTO portname
    FROM ports AS t1, portnames AS t2
    WHERE t1.portid = t2.portid AND t1.pid = pid;

  RETURN portname;
END; //

-------------------------------------------------------------------------------
-- FUNCTION: cuts.get_component_name
-------------------------------------------------------------------------------

DROP FUNCTION IF EXISTS cuts.get_component_name //

CREATE FUNCTION cuts.get_component_name (id INT)
RETURNS VARCHAR (255)
BEGIN
  DECLARE instance VARCHAR (255);

  SELECT component_name INTO instance
    FROM component_instances WHERE component_id = id;

  RETURN instance;
END; //

-------------------------------------------------------------------------------
-- PROCEDURE: cuts.select_component_info_i
-------------------------------------------------------------------------------

DROP PROCEDURE IF EXISTS
  cuts.select_component_info_i //

CREATE PROCEDURE
  cuts.select_component_info_i (IN inst_id INT)
BEGIN
  SELECT t5.*, t6.portname FROM
    (SELECT t3.*, t4.pid, t4.portid, t4.port_type FROM
      (SELECT t1.*, t2.typename FROM component_instances AS t1
        LEFT JOIN component_types AS t2 ON t1.typeid = t2.typeid
        WHERE t1.component_id = inst_id) AS t3
      LEFT JOIN ports AS t4 ON t3.typeid = t4.ctype) AS t5
    LEFT JOIN portnames AS t6 ON t5.portid = t6.portid;
END; //

-------------------------------------------------------------------------------
-- PROCEDURE: cuts.select_component_portnames_i
-------------------------------------------------------------------------------

DROP PROCEDURE IF EXISTS
  cuts.select_component_portnames_i //

CREATE PROCEDURE
  cuts.select_component_portnames_i (IN inst_id INT,
                                     IN porttype VARCHAR(20))
BEGIN
  SELECT t5.pid, t6.portname FROM
    (SELECT t3.*, t4.pid, t4.portid, t4.port_type FROM
      (SELECT t1.*, t2.typename FROM component_instances AS t1
        LEFT JOIN component_types AS t2 ON t1.typeid = t2.typeid
        WHERE t1.component_id = inst_id) AS t3
      LEFT JOIN ports AS t4 ON t3.typeid = t4.ctype
      WHERE t4.port_type = porttype) AS t5
    LEFT JOIN portnames AS t6 ON t5.portid = t6.portid;
END; //

-------------------------------------------------------------------------------
-- PROCEDURE: cuts.select_component_portnames_i
-------------------------------------------------------------------------------

DROP PROCEDURE IF EXISTS
  cuts.select_component_portnames //

CREATE PROCEDURE
  cuts.select_component_portnames (IN instance VARCHAR(255),
                                   IN porttype VARCHAR(20))
BEGIN
  DECLARE inst_id INT;

  SELECT component_id INTO inst_id FROM component_instances
    WHERE component_name = instance;

  CALL cuts.select_component_portnames_i (inst_id, porttype);
END; //

DELIMITER ;

--
-------------------------------------------------------------------------------
