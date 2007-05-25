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

INSERT INTO component_types (typename)
  VALUES ('Unknown');

--
-- Create the table that contains the names of ports.
--

CREATE TABLE IF NOT EXISTS portnames
(
  portid          INT              NOT NULL auto_increment,
  portname        VARCHAR (255),

  PRIMARY KEY (portid),
  UNIQUE (portname)
);

INSERT INTO portnames (portid, portname)
  VALUES (1);

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

INSERT INTO component_instances (typeid, component_name)
  VALUES (1, 'Unknown');

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

INSERT INTO ipaddr_host_map (ipaddr, hostname)
  VALUES ('0.0.0.0', 'unknown'), ('127.0.0.1', 'localhost');

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
-- for users who are allows to view the database.
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