--
-- @file        CUTS-archive.sql
--
-- $Id: CUTS-create.sql 1127 2007-02-04 02:59:21Z hillj $
--
-- @author      James H. Hill
--

USE cuts;

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

  component         int               NOT NULL default 1,
  sender            int               NOT NULL default 1,
  src               int               NOT NULL default 1,
  dst               int                        default 1,

  best_time         int NOT NULL default 0,
  worse_time        int NOT NULL default 0,
  total_time        int NOT NULL default 0,

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
    ON UPDATE CASCADE,
  FOREIGN KEY (src) REFERENCES ports (pid)
    ON DELETE RESTRICT
    ON UPDATE CASCADE,
  FOREIGN KEY (dst) REFERENCES ports (pid)
    ON DELETE RESTRICT
    ON UPDATE CASCADE
);

-- Change the delimiter for creating the procedures. Failing
-- to change the delimit will result in the invalid execution
-- of the SQL statements below.

delimiter //

-------------------------------------------------------------------------------
-- FUNCTION: cuts.insert_execution_time
-------------------------------------------------------------------------------

DROP FUNCTION IF EXISTS cuts.max_collection_time //

CREATE FUNCTION
  cuts.max_collection_time (test INT)
RETURNS DATETIME
BEGIN
  DECLARE max_datetime DATETIME;

  SELECT MAX(collection_time) INTO max_datetime
    FROM execution_time WHERE test_number = test;

  RETURN max_datetime;
END; //

-------------------------------------------------------------------------------
-- PROCEDURE: cuts.insert_execution_time
-------------------------------------------------------------------------------

DROP PROCEDURE IF EXISTS cuts.insert_execution_time //

CREATE PROCEDURE
  cuts.insert_execution_time (IN test INT, IN ctime DATETIME,
                              IN mtype VARCHAR (255), IN mcount INT,
                              IN cname VARCHAR (255), IN sname VARCHAR (255),
                              IN srcname VARCHAR (255), IN dstname VARCHAR (255),
                              IN best INT, IN worst INT, IN total INT)
BEGIN
  DECLARE tid INT;
  DECLARE cid INT;
  DECLARE sid INT;
  DECLARE src_portname_id INT;
  DECLARE dst_portname_id INT;


  -- get the type id of the component
  SELECT typeid INTO tid FROM component_instances
    WHERE component_name = cname LIMIT 1;

  -- get the id of the sender and current component
  SELECT component_id INTO cid FROM component_instances
    WHERE component_name = cname;
  SELECT component_id INTO sid FROM component_instances
    WHERE component_name = sname;

  INSERT INTO execution_time (test_number, collection_time, metric_type,
   metric_count, component, sender, src, dst, best_time, total_time, worse_time)
   VALUES (test, ctime, mtype, mcount, cid, sid,
     (SELECT pid FROM ports WHERE ctype = tid AND
          portid = (SELECT portid FROM portnames WHERE portname = srcname) AND
          port_type = 'sink'),
     (SELECT pid FROM ports WHERE ctype = tid AND
          portid = (SELECT portid FROM portnames WHERE portname = dstname) AND
          port_type = 'source'),
   best, worst, total);

END; //

-------------------------------------------------------------------------------
-- PROCEDURE: cuts.select_execution_time
-------------------------------------------------------------------------------

DROP PROCEDURE IF EXISTS
  cuts.select_execution_time //

CREATE PROCEDURE
  cuts.select_execution_time (IN test INT, IN ctime DATETIME)
BEGIN
  SELECT t9.*, t10.portname AS dstname FROM
    (SELECT t4.*, t8.portname AS srcname FROM
      (SELECT t2.*, t3.component_name FROM
        (SELECT results.*, t1.component_name AS sender_name FROM
          (SELECT *, (total_time / metric_count) AS avg_time FROM execution_time AS e
             WHERE collection_time = ctime AND test_number = test) AS results
         LEFT JOIN component_instances AS t1
             ON t1.component_id = results.sender) AS t2
      LEFT JOIN component_instances AS t3 ON t2.component = t3.component_id) AS t4
    LEFT JOIN
      (SELECT pid, portname FROM ports AS t6, portnames AS t7
         WHERE t6.portid = t7.portid) AS t8 ON t8.pid = t4.src) AS t9
  LEFT JOIN
      (SELECT pid, portname FROM ports AS t11, portnames AS t12
         WHERE t11.portid = t12.portid) AS t10 ON t10.pid = t9.dst;
END; //


-------------------------------------------------------------------------------
-- PROCEDURE: cuts.select_execution_time_ex
-------------------------------------------------------------------------------

DROP PROCEDURE IF EXISTS
  cuts.select_execution_time_ex //

CREATE PROCEDURE
  cuts.select_execution_time_ex (IN test INT, IN ctime DATETIME,
                                 IN cid INT, IN sender_id INT)
BEGIN
  SELECT t9.*, t10.portname AS dstname FROM
    (SELECT t4.*, t8.portname AS srcname FROM
      (SELECT t2.*, t3.component_name FROM
        (SELECT results.*, t1.component_name AS sender_name FROM
          (SELECT *, (total_time / metric_count) AS avg_time FROM execution_time AS e
             WHERE collection_time = ctime AND test_number = test
               AND component = cid AND sender = sender_id) AS results
         LEFT JOIN component_instances AS t1
             ON t1.component_id = results.sender) AS t2
      LEFT JOIN component_instances AS t3 ON t2.component = t3.component_id) AS t4
    LEFT JOIN
      (SELECT pid, portname FROM ports AS t6, portnames AS t7
         WHERE t6.portid = t7.portid) AS t8 ON t8.pid = t4.src) AS t9
  LEFT JOIN
      (SELECT pid, portname FROM ports AS t11, portnames AS t12
         WHERE t11.portid = t12.portid) AS t10 ON t10.pid = t9.dst;
END; //

-------------------------------------------------------------------------------
-- PROCEDURE: select_distinct_components_in_execution_time
-------------------------------------------------------------------------------

DROP PROCEDURE IF EXISTS
  cuts.select_distinct_components_in_execution_time //

CREATE PROCEDURE
  cuts.select_distinct_components_in_execution_time (IN test INT,
                                                     IN ctime DATETIME)
BEGIN
  SELECT DISTINCT component, component_name
    FROM execution_time AS t1
    LEFT JOIN component_instances AS t2
      ON t1.component = t2.component_id
    WHERE t1.test_number = test AND t1.collection_time = ctime
    ORDER BY component_name;
END ; //

delimiter ;

