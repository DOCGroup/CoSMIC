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

  FOREIGN KEY (src) REFERENCES ports (pid)
    ON DELETE RESTRICT
    ON UPDATE CASCADE,

  FOREIGN KEY (dst) REFERENCES ports (pid)
    ON DELETE RESTRICT
    ON UPDATE CASCADE
);

DELIMITER //

-------------------------------------------------------------------------------
-- cuts.select_execution_path_elements_i
-------------------------------------------------------------------------------

DROP PROCEDURE IF EXISTS
  cuts.select_execution_path_elements_i; //

CREATE PROCEDURE
  cuts.select_execution_path_elements_i (IN path INT)
BEGIN
  SELECT t9.*, t10.component_name AS instance_name FROM
    (SELECT t7.*, t8.portname AS dst_portname FROM
      (SELECT t5.*, t6.portid AS dst_portid, t6.port_type AS dst_porttype
        FROM (SELECT t3.*, t4.portname AS src_portname FROM
          (SELECT t1.*, t2.portid AS src_portid, t2.port_type AS src_porttype
            FROM critical_path_elements AS t1
            LEFT JOIN ports AS t2 ON t1.src = t2.pid
            WHERE t1.path_id = path ORDER BY t1.path_order) AS t3
          LEFT JOIN portnames AS t4 ON t3.src_portid = t4.portid) AS t5
        LEFT JOIN ports AS t6 ON t5.dst = t6.pid) AS t7
      LEFT JOIN portnames AS t8 ON t7.dst_portid = t8.portid) AS t9
    LEFT JOIN component_instances AS t10 ON t9.instance = t10.component_id;
END; //

-------------------------------------------------------------------------------
-- cuts.select_execution_path_elements
-------------------------------------------------------------------------------

DROP PROCEDURE IF EXISTS
  cuts.select_execution_path_elements; //

CREATE PROCEDURE
  cuts.select_execution_path_elements (IN pathname VARCHAR(255))
BEGIN
  DECLARE pid INT;

  SELECT path_id INTO pid FROM critical_path
    WHERE path_name = pathname;

  CALL cuts.select_execution_path_elements_i (pid);
END; //

-------------------------------------------------------------------------------
-- cuts.select_execution_path_times_i
-------------------------------------------------------------------------------

DROP PROCEDURE IF EXISTS
  cuts.select_execution_path_times_i; //

CREATE PROCEDURE
  cuts.select_execution_path_times_i (IN test INT, IN path INT)
BEGIN
  SELECT t13.* FROM critical_path_elements AS cp
    LEFT JOIN (SELECT t9.*, t10.portname AS dstname FROM
      (SELECT t4.*, t8.portname AS srcname FROM
        (SELECT t2.*, t3.component_name FROM
          (SELECT results.*, t1.component_name AS sender_name FROM
            (SELECT *, (total_time / metric_count) AS avg_time FROM execution_time AS e
              WHERE test_number = test) AS results
          LEFT JOIN component_instances AS t1
              ON t1.component_id = results.sender) AS t2
        LEFT JOIN component_instances AS t3 ON t2.component = t3.component_id) AS t4
      LEFT JOIN
        (SELECT pid, portname FROM ports AS t6, portnames AS t7
          WHERE t6.portid = t7.portid) AS t8 ON t8.pid = t4.src) AS t9
    LEFT JOIN
        (SELECT pid, portname FROM ports AS t11, portnames AS t12
           WHERE t11.portid = t12.portid) AS t10 ON t10.pid = t9.dst) AS t13
    ON cp.instance = t13.component AND cp.src = t13.src AND
      (cp.dst = t13.dst OR t13.dst IS NULL)
    WHERE cp.path_id = path
    ORDER BY t13.collection_time, cp.path_order;
END; //

-------------------------------------------------------------------------------
-- cuts.select_execution_path_times
-------------------------------------------------------------------------------

DROP PROCEDURE IF EXISTS
  cuts.select_execution_path_times; //

CREATE PROCEDURE
  cuts.select_execution_path_times (IN test INT,
                                    IN pathname VARCHAR (255))
BEGIN
  DECLARE pid INT;

  SELECT path_id INTO pid FROM cuts.critical_path
    WHERE path_name = pathname;

  CALL cuts.select_execution_path_times_i (test, pid);
END; //

-------------------------------------------------------------------------------
-- cuts.select_execution_path_names_all
-------------------------------------------------------------------------------

DROP PROCEDURE IF EXISTS
  cuts.select_execution_path_names_all; //

CREATE PROCEDURE
  cuts.select_execution_path_names_all ()
BEGIN
  SELECT * FROM critical_path;
END; //

-------------------------------------------------------------------------------
-- cuts.execution_path_deadline_i
-------------------------------------------------------------------------------

DROP FUNCTION IF EXISTS
  cuts.execution_path_deadline_i; //

CREATE FUNCTION
  cuts.execution_path_deadline_i (path INT)
  RETURNS INT
BEGIN
  DECLARE ep_deadline INT;

  SELECT deadline INTO ep_deadline FROM cuts.critical_path
    WHERE path_id = path;

  RETURN ep_deadline;
END; //

-------------------------------------------------------------------------------
-- cuts.execution_path_deadline
-------------------------------------------------------------------------------

DROP FUNCTION IF EXISTS
  cuts.execution_path_deadline; //

CREATE FUNCTION
  cuts.execution_path_deadline (pathname VARCHAR(255))
  RETURNS INT
BEGIN
  DECLARE ep_deadline INT;

  SELECT deadline INTO ep_deadline FROM cuts.critical_path
    WHERE path_name = path;

  RETURN ep_deadline;
END; //

DELIMITER ;
