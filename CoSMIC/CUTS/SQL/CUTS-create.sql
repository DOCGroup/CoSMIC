--
-- @file        CUTS-create.sql
--
-- $Id$
--
-- @author      James H. Hill
--

--
-- create the CUTS database
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
  test_number   int             NOT NULL auto_increment,
  test_name     varchar (255),

  start_time    datetime,
  stop_time     datetime,

  status        enum ('inactive',
                      'active',
                      'complete'),

  -- set the contraints for the table
  PRIMARY KEY (test_number)
);

--
-- Table structure for table cuts.component
--
-- This table contains the mapping of UUIDs their appropriate
-- component name. The UUID is the primary key for the table
-- because no two components can have the same UUID regardless
-- of them being located in two totally different deployments,
-- or systems.
--

CREATE TABLE IF NOT EXISTS component_instances
(
  component_id    int             NOT NULL auto_increment,
  component_name  varchar (512)   default NULL,

  PRIMARY KEY (component_id),
  UNIQUE      (component_name)
);

--
-- Create the table that contains all the critical paths created by the
-- user. The elements in path apprear in cuts.critical_path_elements table.
--

CREATE TABLE IF NOT EXISTS critical_path
(
  path_id       INT             NOT NULL auto_increment,
  path_name     VARCHAR (32),
  deadline      INT             NOT NULL DEFAULT 250,

  PRIMARY KEY (path_id)
);

--
-- Create the table that contains the elements for the paths contained in
-- cuts.critical_path. This table is constructed such that any path that
-- is deleted from cuts.critical_path will remove all path elements in
-- this table. Also, if component instances ids are changed, they are
-- reflected in this table, and components instances aren't allowd to be
-- deleted if their id appears in this column.
--

CREATE TABLE IF NOT EXISTS critical_path_elements
(
  path_id       INT             NOT NULL,
  path_order    INT             NOT NULL,
  instance      INT             NOT NULL,
  src           VARCHAR (255)   NOT NULL,
  dst           VARCHAR (255)   NOT NULL,

  PRIMARY KEY (path_id, path_order),
  FOREIGN KEY (path_id) REFERENCES critical_path (path_id)
    ON DELETE CASCADE
    ON UPDATE CASCADE,
  FOREIGN KEY (instance) REFERENCES component_instances (component_id)
    ON DELETE RESTRICT
    ON UPDATE CASCADE
);

--
-- Table structure for table wlgbenchmark.iphost
--

CREATE TABLE IF NOT EXISTS ipaddr_host_map
(
  hostid      INT               NOT NULL auto_increment,
  ipaddr      VARCHAR (40)      NOT NULL,
  v4          BOOLEAN           NOT NULL DEFAULT true,
  hostname    VARCHAR (255),

  PRIMARY KEY (hostid)
);

INSERT INTO ipaddr_host_map (ipaddr, v4, hostname)
  VALUES ('127.0.0.1', 1, 'localhost');
  
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
-- Create the execution_time table. This table contains
-- the overall execution times for various paths in a
-- component. These paths can be sequences together to
-- determine the end-to-end execution time of a path in
-- a system
--

CREATE TABLE IF NOT EXISTS execution_time
(
  test_number       int         NOT NULL,
  collection_time   datetime    NOT NULL,

  -- either 'transit' or 'process' for the time being
  metric_type       enum ('transit',
                          'queue',
                          'process')  NOT NULL,
  metric_count      int               NOT NULL,

  component         int               NOT NULL  default 0,
  sender            int               NOT NULL  default 0,
  src               varchar (255)     NOT NULL  default 'unknown',
  dst               varchar (255)               default NULL,

  best_time         int NOT NULL default 0,
  average_time      int NOT NULL default 0,
  worse_time        int NOT NULL default 0,

  INDEX (test_number),
  INDEX (collection_time),
  INDEX (test_number, collection_time),

  FOREIGN KEY (test_number) REFERENCES tests (test_number)
    ON DELETE CASCADE,
  FOREIGN KEY (component) REFERENCES component_instances (component_id)
    ON DELETE RESTRICT
    ON UPDATE CASCADE,
  FOREIGN KEY (sender) REFERENCES component_instances (component_id)
    ON DELETE RESTRICT
    ON UPDATE CASCADE
);

--
-- Create the 'deployment_table'. This table contains the location
-- uptime and downtime of a component instance per test.
--

CREATE TABLE IF NOT EXISTS deployment_table
(
  test_number       INT NOT NULL,
  instance          INT NOT NULL,
  hostid            INT NOT NULL,
  uptime            DATETIME,
  downtime          DATETIME,

  FOREIGN KEY (test_number) REFERENCES tests (test_number)
    ON DELETE CASCADE,
  FOREIGN KEY (instance) REFERENCES component_instances (component_id)
    ON DELETE RESTRICT
);

--
-- Create the 'testenv' table. This table is for configuring the
-- testing environment. It contains the corbaloc's for the cutsnode_d
-- for communicating w/ each individual node.
--

CREATE TABLE IF NOT EXISTS testenv
(
  idtag         INT NOT NULL auto_increment,
  hostid        INT,
  portnum       INT(5),
  
  PRIMARY KEY (idtag), 
  UNIQUE (hostid, portnum), 
  FOREIGN KEY (hostid) REFERENCES ipaddr_host_map (hostid)
    ON DELETE RESTRICT 
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