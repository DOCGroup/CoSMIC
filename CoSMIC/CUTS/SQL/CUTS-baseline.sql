--
-- @file        CUTS-baseline.sql
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
-- Create the baseline table. This table contains baseline
-- metric information to each component instance type,
-- per host.
--

CREATE TABLE IF NOT EXISTS baseline
(
  bid             INT             NOT NULL auto_increment,
  instance        INT             NOT NULL,
  host            INT             NOT NULL DEFAULT 0,
  inport          VARCHAR(255)    NOT NULL,
  outport         VARCHAR(255)    NOT NULL,
  metric_count    INT             NOT NULL,
  metric_total    INT             NOT NULL,

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
    ON UPDATE CASCADE
);
