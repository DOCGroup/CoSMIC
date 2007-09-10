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

CREATE PROCEDURE
insert_execution_time (IN test INT, IN ctime DATETIME,
                       IN mtype VARCHAR (255), IN mcount INT,
                       IN cname VARCHAR (255), IN sname VARCHAR (255),
                       IN srcname VARCHAR (255), IN dstname VARCHAR (255),
                       IN best INT, IN worst INT, IN total INT)
BEGIN
  DECLARE tid INT;

  -- get the type id of the component
  SELECT typeid INTO tid FROM component_instances
    WHERE component_name = cname LIMIT 1;

  INSERT INTO execution_time (test_number, collection_time, metric_type,
   metric_count, component, sender, src, dst, best_time, total_time, worse_time)
   VALUES (test, ctime, mtype, mcount,
     (SELECT component_id FROM component_instances WHERE component_name = cname),
     (SELECT component_id FROM component_instances WHERE component_name = sname),
     (SELECT pid FROM ports WHERE ctype = tid AND
          portid = (SELECT portid FROM portnames WHERE portname = srcname) AND
          port_type = 'sink'),
     (SELECT pid FROM ports WHERE ctype = tid AND
          portid = (SELECT portid FROM portnames WHERE portname = dstname) AND
          port_type = 'source'),
   best, worst, total);

END; //

--CREATE PROCEDURE
--select_execution_times (IN test INT, IN ctime DATETIME,
--                        IN component_id INT, IN sender_id INT)
--BEGIN
--
--END; //

delimiter ;
