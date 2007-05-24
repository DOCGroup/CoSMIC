--
-- @file        CUTS-path-analysis.sql
--
-- $Id: CUTS-create.sql 1127 2007-02-04 02:59:21Z hillj $
--
-- @author      James H. Hill
--

USE cuts;

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
  path_id       INT  NOT NULL,
  path_order    INT  NOT NULL,
  instance      INT  NOT NULL,
  src           INT  NOT NULL,
  dst           INT  NOT NULL,

  PRIMARY KEY (path_id, path_order),
  FOREIGN KEY (path_id) REFERENCES critical_path (path_id)
    ON DELETE CASCADE
    ON UPDATE CASCADE,
  FOREIGN KEY (instance) REFERENCES component_instances (component_id)
    ON DELETE RESTRICT
    ON UPDATE CASCADE,
  FOREIGN KEY (src) REFERENCES portnames (portid)
    ON DELETE RESTRICT
    ON UPDATE CASCADE,
  FOREIGN KEY (dst) REFERENCES portnames (portid)
    ON DELETE RESTRICT
    ON UPDATE CASCADE
);

