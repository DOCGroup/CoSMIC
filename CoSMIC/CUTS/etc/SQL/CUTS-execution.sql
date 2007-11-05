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
  worst_time        int NOT NULL default 0,
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
-- FUNCTION: cuts.get_insert_execution_time
-------------------------------------------------------------------------------

DROP FUNCTION IF EXISTS cuts.get_max_collection_time //

CREATE FUNCTION
  cuts.get_max_collection_time (test INT)
RETURNS DATETIME
BEGIN
  DECLARE max_datetime DATETIME;

  SELECT MAX(collection_time) INTO max_datetime
    FROM execution_time WHERE test_number = test;

  RETURN max_datetime;
END; //

-------------------------------------------------------------------------------
-- FUNCTION: cuts.get_distinct_component_count
-------------------------------------------------------------------------------

DROP FUNCTION IF EXISTS cuts.get_distinct_component_count //

CREATE FUNCTION
  cuts.get_distinct_component_count (test INT,
                                     coll_time DATETIME)
RETURNS INT
BEGIN
  DECLARE distinct_count INT;

  SELECT COUNT(DISTINCT component) INTO distinct_count
    FROM execution_time
    WHERE test_number = test AND collection_time = coll_time;

  RETURN distinct_count;
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
   metric_count, component, sender, src, dst, best_time, total_time, worst_time)
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
         WHERE t11.portid = t12.portid) AS t10 ON t10.pid = t9.dst
  ORDER BY t9.component_name, srcname, dstname;
END; //

-------------------------------------------------------------------------------
-- PROCEDURE: cuts.select_distinct_collection_times
-------------------------------------------------------------------------------

DROP PROCEDURE IF EXISTS
  cuts.select_distinct_collection_times //

CREATE PROCEDURE
  cuts.select_distinct_collection_times (IN test INT)
BEGIN
  SELECT DISTINCT collection_time
    FROM execution_time  WHERE test_number = test;
END; //

-------------------------------------------------------------------------------
-- PROCEDURE: cuts.select_execution_time_with_limits
-------------------------------------------------------------------------------

DROP PROCEDURE IF EXISTS
  cuts.select_execution_time_with_limits //

CREATE PROCEDURE
  cuts.select_execution_time_with_limits (IN test INT,
                                          IN ctime DATETIME,
                                          IN start_index INT,
                                          IN numrecs INT)
BEGIN
  SET @test = test;
  SET @collection_time = ctime;
  SET @offset = start_index;
  SET @rows = numrecs;

  -- prepare the statement for usage.
  PREPARE STMT FROM
    "SELECT t9.*, t10.portname AS dstname FROM
      (SELECT t4.*, t8.portname AS srcname FROM
        (SELECT t2.*, t3.component_name FROM
          (SELECT results.*, t1.component_name AS sender_name FROM
            (SELECT *, (total_time / metric_count) AS avg_time FROM execution_time AS e
              WHERE collection_time = ? AND test_number = ?) AS results
          LEFT JOIN component_instances AS t1
              ON t1.component_id = results.sender) AS t2
        LEFT JOIN component_instances AS t3 ON t2.component = t3.component_id) AS t4
      LEFT JOIN
        (SELECT pid, portname FROM ports AS t6, portnames AS t7
          WHERE t6.portid = t7.portid) AS t8 ON t8.pid = t4.src) AS t9
    LEFT JOIN
        (SELECT pid, portname FROM ports AS t11, portnames AS t12
          WHERE t11.portid = t12.portid) AS t10 ON t10.pid = t9.dst
    ORDER BY t9.component_name LIMIT ?, ?";

  -- execute the statement using limits
  EXECUTE STMT USING @collection_time, @test, @offset, @rows;
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

-------------------------------------------------------------------------------
-- PROCEDURE: cuts.select_overall_component_processing_time_all
-------------------------------------------------------------------------------

DROP PROCEDURE IF EXISTS
  cuts.select_overall_component_processing_time_all //

CREATE PROCEDURE
  cuts.select_overall_component_processing_time_all (IN test INT)
BEGIN
  SELECT component, src, dst, SUM(metric_count) AS total_event_count,
      MIN(best_time) AS abs_min_time,
      SUM(total_time) / SUM(metric_count) AS overall_avg_time,
      MAX(worst_time) AS abs_max_time
    FROM execution_time
    WHERE test_number = test AND metric_type = 'process'
    GROUP BY dst;
END ; //

-------------------------------------------------------------------------------
-- PROCEDURE: cuts.select_overall_component_processing_time_i
-------------------------------------------------------------------------------

DROP PROCEDURE IF EXISTS
  cuts.select_overall_component_processing_time_i //

CREATE PROCEDURE
  cuts.select_overall_component_processing_time_i (IN test INT,
                                                   IN inst INT)
BEGIN
  SELECT component, src, dst, SUM(metric_count) AS total_event_count,
      MIN(best_time) AS abs_min_time,
      SUM(total_time) / SUM(metric_count) AS overall_avg_time,
      MAX(worst_time) AS abs_max_time
    FROM execution_time
    WHERE test_number = test AND component = inst AND metric_type = 'process'
    GROUP BY dst;
END ; //

-------------------------------------------------------------------------------
-- PROCEDURE: cuts.select_overall_component_processing_time
-------------------------------------------------------------------------------

DROP PROCEDURE IF EXISTS
  cuts.select_overall_component_processing_time //

CREATE PROCEDURE
  cuts.select_overall_component_processing_time (IN test INT,
                                                 IN inst VARCHAR(255))
BEGIN
  DECLARE inst_id INT;

  SELECT component_id INTO inst_id FROM component_instances
    WHERE component_name = inst;

  CALL cuts.select_overall_component_processing_time(test, inst_id);
END ; //

-------------------------------------------------------------------------------
-- PROCEDURE: cuts.select_execution_time_cumulative
-------------------------------------------------------------------------------

DROP PROCEDURE IF EXISTS
  cuts.select_execution_time_cumulative //

CREATE PROCEDURE
  cuts.select_execution_time_cumulative (IN test INT)
BEGIN
  SELECT t9.*, t10.portname AS dstname FROM
    (SELECT t4.*, t8.portname AS srcname FROM
      (SELECT t2.*, t3.component_name FROM
        (SELECT results.*, t1.component_name AS sender_name FROM
          (SELECT test_number, component, sender, src, dst, metric_type, SUM(metric_count) AS metric_count,
             MIN(best_time) AS best_time,  SUM(total_time) / SUM(metric_count) AS avg_time,
             MAX(worst_time) AS worst_time FROM execution_time AS e
             WHERE test_number = test
             GROUP BY component, metric_type, src, dst
             ORDER BY collection_time) AS results
         LEFT JOIN component_instances AS t1
             ON t1.component_id = results.sender) AS t2
      LEFT JOIN component_instances AS t3 ON t2.component = t3.component_id) AS t4
    LEFT JOIN
      (SELECT pid, portname FROM ports AS t6, portnames AS t7
         WHERE t6.portid = t7.portid) AS t8 ON t8.pid = t4.src) AS t9
  LEFT JOIN
      (SELECT pid, portname FROM ports AS t11, portnames AS t12
         WHERE t11.portid = t12.portid) AS t10 ON t10.pid = t9.dst
  ORDER BY t9.component_name, srcname, dstname;
END ; //

-------------------------------------------------------------------------------
-- PROCEDURE: cuts.select_execution_time_delta
-------------------------------------------------------------------------------

DROP PROCEDURE IF EXISTS
  cuts.select_execution_time_delta //

CREATE PROCEDURE
  cuts.select_execution_time_delta (IN test INT, IN coll_time DATETIME)
BEGIN
  SELECT
      t1.test_number, t1.collection_time, t1.component, t1.sender, t1.src, t1.dst,
      t1.best_time - t2.best_time AS best_time,
      (t1.total_time / t1.metric_count) - (t2.total_time / t2.event_count) AS avg_time,
      t1.worst_time - t2.worst_time AS worst_time
    FROM execution_time AS t1, baseline AS t2
    WHERE t1.test_number = test AND t1.collection_time = coll_time
      AND t1.component = t2.instance AND t1.src = t2.inport
      AND t1.dst = t2.outport
    ORDER BY t1.component, t1.src, t1.dst, t1.sender;
END ; //

-------------------------------------------------------------------------------
-- PROCEDURE: cuts.select_execution_time_cumulative_delta
-------------------------------------------------------------------------------

DROP PROCEDURE IF EXISTS
  cuts.select_execution_time_cumulative_delta //

CREATE PROCEDURE
  cuts.select_execution_time_cumulative_delta (IN test INT)
BEGIN
  SELECT
      t1.test_number, t1.component, t1.sender, t1.src, t1.dst,
      SUM(t1.metric_count) AS metric_count,
      MIN(t1.best_time) - t2.best_time AS best_time,
      (SUM(t1.total_time) / SUM(t1.metric_count)) - (t2.total_time / t2.event_count) AS avg_time,
      MAX(t1.worst_time) - t2.worst_time AS worst_time
  FROM execution_time AS t1, baseline AS t2
  WHERE t1.test_number = test
        AND t1.component = t2.instance AND t1.src = t2.inport
        AND t1.dst = t2.outport
  GROUP BY component, metric_type, src, dst
  ORDER BY collection_time;
END ; //

delimiter ;
