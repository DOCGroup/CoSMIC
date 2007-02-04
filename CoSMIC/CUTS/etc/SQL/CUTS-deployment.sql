--
-- @file        CUTS-deployment.sql
--
-- $Id: CUTS-baseline.sql 1114 2007-02-01 23:55:29Z hillj $
--
-- @author      James H. Hill
--

USE cuts;

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
