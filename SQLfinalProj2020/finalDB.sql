-- MySQL dump 10.13  Distrib 8.0.19, for Win64 (x86_64)
--
-- Host: 127.0.0.1    Database: opaldb
-- ------------------------------------------------------
-- Server version	8.0.19

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!50503 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `book`
--

DROP TABLE IF EXISTS `book`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `book` (
  `book_sn` int NOT NULL AUTO_INCREMENT,
  `group_id` int NOT NULL,
  `book_price` float NOT NULL,
  `location` varchar(45) NOT NULL,
  `condition` varchar(45) NOT NULL,
  PRIMARY KEY (`book_sn`),
  KEY `group_id2_idx` (`group_id`),
  CONSTRAINT `group_id2` FOREIGN KEY (`group_id`) REFERENCES `book_group_id` (`group_id`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB AUTO_INCREMENT=26 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `book`
--

LOCK TABLES `book` WRITE;
/*!40000 ALTER TABLE `book` DISABLE KEYS */;
INSERT INTO `book` VALUES (1,3,25,'storage','bn'),(2,4,36,'store','n'),(3,5,245,'store','b'),(4,6,100,'storage','o'),(11,6,120,'store','bn'),(12,7,80,'store','m'),(13,8,25,'storage','n'),(14,12,50,'storage','bn'),(15,13,60,'store','n'),(16,14,100,'store','b'),(20,15,50,'store','bn'),(21,3,50,'store','n'),(22,16,50,'store','n'),(23,17,60,'store','bn'),(24,18,25,'storage','n'),(25,19,40,'store','n');
/*!40000 ALTER TABLE `book` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `book_authors`
--

DROP TABLE IF EXISTS `book_authors`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `book_authors` (
  `book_sn` int NOT NULL,
  `author` varchar(45) NOT NULL,
  PRIMARY KEY (`book_sn`,`author`),
  CONSTRAINT `book_sn` FOREIGN KEY (`book_sn`) REFERENCES `book` (`book_sn`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `book_authors`
--

LOCK TABLES `book_authors` WRITE;
/*!40000 ALTER TABLE `book_authors` DISABLE KEYS */;
INSERT INTO `book_authors` VALUES (1,'guy'),(1,'opal'),(2,'dekel'),(3,'sivan'),(4,'danit'),(11,'keren'),(12,'itamar'),(13,'ela'),(14,'gali'),(15,'yoav'),(16,'efrat');
/*!40000 ALTER TABLE `book_authors` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `book_group_id`
--

DROP TABLE IF EXISTS `book_group_id`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `book_group_id` (
  `group_id` int NOT NULL AUTO_INCREMENT,
  `book_name` varchar(45) NOT NULL,
  `translator` varchar(45) NOT NULL,
  `publisher_name` varchar(45) NOT NULL,
  `publisher_year` int NOT NULL,
  `pages` int NOT NULL,
  `weight` float NOT NULL,
  PRIMARY KEY (`group_id`),
  KEY `book_name` (`book_name`)
) ENGINE=InnoDB AUTO_INCREMENT=20 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `book_group_id`
--

LOCK TABLES `book_group_id` WRITE;
/*!40000 ALTER TABLE `book_group_id` DISABLE KEYS */;
INSERT INTO `book_group_id` VALUES (3,'harry','poter','ron',2012,345,0.56),(4,'good sql','guy','opal',2013,435,1.3),(5,'coding','dekel menashe','kineret',2017,14,0.1),(6,'water flow','ron kivson','orgad',1987,368,0.6),(7,'rise of machines','arnold ','robo cop',1998,647,1),(8,'hot in the sun','sunny bunny','Mr rabbit',1234,612,1.2),(9,'algebra','rick ','morty',1683,251,0.29),(12,'coding','korman','guy',1984,231,0.89),(13,'big burgers','sponge bob','patrick',2020,35,0.34),(14,'cactus','roses','violets',1945,456,2.8),(15,'harry','pit','ema',2012,345,0.56),(16,'po the bear','bell','adir',2013,200,0.9),(17,'tarazn','guy','opal',2014,210,0.23),(18,'cinderella','peretz','moshe',2015,220,0.2),(19,'mr bean','bibi','sara',2015,300,0.12);
/*!40000 ALTER TABLE `book_group_id` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `costumer_cellphones`
--

DROP TABLE IF EXISTS `costumer_cellphones`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `costumer_cellphones` (
  `costumer_id` varchar(45) NOT NULL,
  `cellphone` varchar(45) NOT NULL,
  PRIMARY KEY (`cellphone`),
  KEY `costumer_id_idx` (`costumer_id`),
  CONSTRAINT `costumer_id` FOREIGN KEY (`costumer_id`) REFERENCES `costumers` (`costumer_id`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `costumer_cellphones`
--

LOCK TABLES `costumer_cellphones` WRITE;
/*!40000 ALTER TABLE `costumer_cellphones` DISABLE KEYS */;
INSERT INTO `costumer_cellphones` VALUES ('234535678','0527485927'),('325754635','0563857245'),('346478432','0512485242'),('346547756','0523758292'),('346673167','0523412468'),('457457547','0534522214'),('485929344','0523422411'),('547856743','0521144459'),('654715246','0525252367'),('774564574','0522559099');
/*!40000 ALTER TABLE `costumer_cellphones` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `costumer_orders`
--

DROP TABLE IF EXISTS `costumer_orders`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `costumer_orders` (
  `order_num` int NOT NULL,
  `costumer_id` varchar(45) NOT NULL,
  `order_date` date NOT NULL,
  PRIMARY KEY (`order_num`),
  KEY `costumer_id_idx1` (`costumer_id`),
  CONSTRAINT `costumer_id1` FOREIGN KEY (`costumer_id`) REFERENCES `costumers` (`costumer_id`) ON DELETE CASCADE ON UPDATE CASCADE,
  CONSTRAINT `order_num` FOREIGN KEY (`order_num`) REFERENCES `orders` (`order_num`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `costumer_orders`
--

LOCK TABLES `costumer_orders` WRITE;
/*!40000 ALTER TABLE `costumer_orders` DISABLE KEYS */;
INSERT INTO `costumer_orders` VALUES (1,'234535678','2020-03-11'),(2,'325754635','2020-07-11'),(3,'346478432','2020-11-11'),(4,'346547756','2019-03-11'),(5,'346673167','2019-03-15'),(6,'457457547','2019-03-09'),(7,'485929344','2019-08-11'),(8,'547856743','2019-12-11'),(9,'654715246','2019-10-01'),(10,'774564574','2019-03-28');
/*!40000 ALTER TABLE `costumer_orders` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `costumers`
--

DROP TABLE IF EXISTS `costumers`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `costumers` (
  `costumer_id` varchar(45) NOT NULL,
  `f_name` varchar(45) NOT NULL,
  `l_name` varchar(45) NOT NULL,
  `landline` varchar(45) DEFAULT NULL,
  `join_date` date NOT NULL,
  PRIMARY KEY (`costumer_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `costumers`
--

LOCK TABLES `costumers` WRITE;
/*!40000 ALTER TABLE `costumers` DISABLE KEYS */;
INSERT INTO `costumers` VALUES ('234535678','gil','isban',NULL,'2019-12-05'),('325754635','gary','anan',NULL,'2019-03-05'),('346478432','sami','satlan','032464910','2019-10-05'),('346547756','hanni','matan','094536593','2020-09-18'),('346673167','tami','mutshan',NULL,'2020-04-06'),('457457547','gili','eilan',NULL,'2020-10-26'),('485929344','gal','hanan',NULL,'2020-10-16'),('547856743','ami','eran',NULL,'2018-04-07'),('654715246','gon','shanan',NULL,'2018-11-07'),('774564574','gitit','nitsan',NULL,'2018-10-07');
/*!40000 ALTER TABLE `costumers` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `deliveries`
--

DROP TABLE IF EXISTS `deliveries`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `deliveries` (
  `tracking_code` int NOT NULL AUTO_INCREMENT,
  `cost` float NOT NULL,
  `del_status` varchar(45) NOT NULL,
  `company` varchar(45) NOT NULL,
  `costumer_id` varchar(45) NOT NULL,
  `transaction_id` int NOT NULL,
  `method` varchar(45) NOT NULL,
  PRIMARY KEY (`tracking_code`),
  KEY `transaction_id_idx` (`transaction_id`),
  CONSTRAINT `transaction_id` FOREIGN KEY (`transaction_id`) REFERENCES `transactions` (`transaction_id`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB AUTO_INCREMENT=21 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `deliveries`
--

LOCK TABLES `deliveries` WRITE;
/*!40000 ALTER TABLE `deliveries` DISABLE KEYS */;
INSERT INTO `deliveries` VALUES (1,15,'deliverd','post','234535678',1,'mail'),(2,15,'deliverd','post','325754635',2,'r_delivery'),(3,15,'deliverd','xpress','346478432',3,'delivery'),(4,60,'deliverd','xpress','346547756',4,'f_delivery'),(5,15,'sent','xpress','346673167',5,'pickup'),(6,15,'deliverd','post','457457547',7,'f_delivery'),(7,20,'deliverd','post','457457547',7,'delivery'),(8,30,'deliverd','post','547856743',8,'regular'),(9,15,'deliverd','post','547856743',8,'mail'),(10,15,'deliverd','xpress','774564574',10,'mail'),(18,77,'deliverd','xpress','234535678',12,'mail'),(20,15,'deliverd','xpress','547856743',99,'mail');
/*!40000 ALTER TABLE `deliveries` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `deliveries_items`
--

DROP TABLE IF EXISTS `deliveries_items`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `deliveries_items` (
  `tracking_code` int NOT NULL,
  `group_id` int NOT NULL,
  `quantity` int NOT NULL,
  PRIMARY KEY (`tracking_code`,`group_id`),
  KEY `group_id4_idx` (`group_id`),
  CONSTRAINT `group_id4` FOREIGN KEY (`group_id`) REFERENCES `book_group_id` (`group_id`) ON DELETE CASCADE ON UPDATE CASCADE,
  CONSTRAINT `tracking_code` FOREIGN KEY (`tracking_code`) REFERENCES `deliveries` (`tracking_code`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `deliveries_items`
--

LOCK TABLES `deliveries_items` WRITE;
/*!40000 ALTER TABLE `deliveries_items` DISABLE KEYS */;
INSERT INTO `deliveries_items` VALUES (1,3,1),(2,4,1),(3,8,1),(4,8,1),(5,5,1),(6,12,2),(7,3,1),(8,5,1),(9,3,1),(9,4,1),(9,7,1),(10,5,1),(18,3,1),(18,15,1);
/*!40000 ALTER TABLE `deliveries_items` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `locations_quantity`
--

DROP TABLE IF EXISTS `locations_quantity`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `locations_quantity` (
  `location` varchar(45) NOT NULL,
  `date` date NOT NULL,
  `quantity` int NOT NULL,
  PRIMARY KEY (`location`,`date`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `locations_quantity`
--

LOCK TABLES `locations_quantity` WRITE;
/*!40000 ALTER TABLE `locations_quantity` DISABLE KEYS */;
INSERT INTO `locations_quantity` VALUES ('storage','2016-10-01',0),('storage','2019-01-01',3),('storage','2019-02-01',3),('storage','2019-04-01',4),('store','2016-10-01',1),('store','2017-01-01',2),('store','2018-01-01',1),('store','2019-01-01',5),('store','2019-02-01',5),('store','2020-12-01',6);
/*!40000 ALTER TABLE `locations_quantity` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `orders`
--

DROP TABLE IF EXISTS `orders`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `orders` (
  `order_num` int NOT NULL AUTO_INCREMENT,
  `book_name` varchar(45) NOT NULL,
  `costumer_id` varchar(45) NOT NULL,
  `o_status` varchar(45) NOT NULL,
  `contact_date` date DEFAULT NULL,
  PRIMARY KEY (`order_num`),
  KEY `costumer_id3_idx` (`costumer_id`),
  CONSTRAINT `costumer_id3` FOREIGN KEY (`costumer_id`) REFERENCES `costumers` (`costumer_id`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB AUTO_INCREMENT=11 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `orders`
--

LOCK TABLES `orders` WRITE;
/*!40000 ALTER TABLE `orders` DISABLE KEYS */;
INSERT INTO `orders` VALUES (1,'aladin','234535678','waiting',NULL),(2,'ami tami','325754635','waiting',NULL),(3,'home alone','346478432','waiting',NULL),(4,'data analisis','346547756','waiting',NULL),(5,'tom and jerry','346673167','waiting',NULL),(6,'mr bean','457457547','updated','2019-04-19'),(7,'cinderella','485929344','updated','2019-04-19'),(8,'tarazn','547856743','updated','2019-10-19'),(9,'po the bear','654715246','updated','2019-04-13'),(10,'palm beach','774564574','waiting',NULL);
/*!40000 ALTER TABLE `orders` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `payments`
--

DROP TABLE IF EXISTS `payments`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `payments` (
  `salaries` float NOT NULL,
  `rent` float NOT NULL,
  `store_purch` float NOT NULL,
  `cellphone` float NOT NULL,
  `landline` float NOT NULL,
  `electricity` float NOT NULL,
  `water` float NOT NULL,
  `city_tax` float NOT NULL,
  `date_y` int NOT NULL,
  `date_m` int NOT NULL,
  `general` float DEFAULT NULL,
  PRIMARY KEY (`date_y`,`date_m`),
  KEY `date_m` (`date_m`),
  KEY `date_y` (`date_y`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `payments`
--

LOCK TABLES `payments` WRITE;
/*!40000 ALTER TABLE `payments` DISABLE KEYS */;
INSERT INTO `payments` VALUES (0,1500,50,30,20,240,90,600,2017,1,NULL),(0,1500,55,30,20,240,90,600,2018,1,NULL),(0,1500,0,30,20,240,90,600,2018,2,NULL),(0,1500,178.5,30,20,240,90,600,2019,1,NULL),(0,1500,0,30,20,240,90,600,2019,2,NULL),(0,1500,25,30,20,240,90,600,2019,10,NULL),(2250,1500,13.5,30,20,250,100,600,2020,3,NULL),(2000,1500,0,30,20,300,120,600,2020,4,NULL),(1000,1500,0,30,20,240,90,600,2020,5,NULL),(0,1500,25,30,20,240,90,600,2020,6,NULL);
/*!40000 ALTER TABLE `payments` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `purchases`
--

DROP TABLE IF EXISTS `purchases`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `purchases` (
  `purch_num` int NOT NULL AUTO_INCREMENT,
  `bought_price` float NOT NULL,
  `quantity` int NOT NULL,
  `purch_date` date NOT NULL,
  PRIMARY KEY (`purch_num`)
) ENGINE=InnoDB AUTO_INCREMENT=12 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `purchases`
--

LOCK TABLES `purchases` WRITE;
/*!40000 ALTER TABLE `purchases` DISABLE KEYS */;
INSERT INTO `purchases` VALUES (1,13.5,1,'2019-01-20'),(2,45,1,'2019-01-01'),(3,25,1,'2020-06-01'),(4,25,1,'2019-10-06'),(5,30,1,'2016-10-01'),(6,35,1,'2019-01-23'),(7,40,1,'2019-01-06'),(8,45,1,'2019-01-01'),(9,50,1,'2017-01-01'),(10,55,1,'2018-01-01');
/*!40000 ALTER TABLE `purchases` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `purchases_books`
--

DROP TABLE IF EXISTS `purchases_books`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `purchases_books` (
  `book_sn` int NOT NULL,
  `purch_num` int NOT NULL,
  `book_price` float DEFAULT NULL,
  PRIMARY KEY (`book_sn`),
  KEY `purch_num_idx` (`purch_num`),
  CONSTRAINT `book_sn4` FOREIGN KEY (`book_sn`) REFERENCES `book` (`book_sn`) ON DELETE CASCADE ON UPDATE CASCADE,
  CONSTRAINT `purch_num` FOREIGN KEY (`purch_num`) REFERENCES `purchases` (`purch_num`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `purchases_books`
--

LOCK TABLES `purchases_books` WRITE;
/*!40000 ALTER TABLE `purchases_books` DISABLE KEYS */;
INSERT INTO `purchases_books` VALUES (1,1,13.5),(2,2,45),(3,3,25),(4,4,25),(11,5,30),(12,6,35),(13,7,40),(14,8,45),(15,9,50),(16,10,55);
/*!40000 ALTER TABLE `purchases_books` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `salaries`
--

DROP TABLE IF EXISTS `salaries`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `salaries` (
  `worker_id` varchar(45) NOT NULL,
  `date_m` int NOT NULL,
  `date_y` int NOT NULL,
  `working_hours` float DEFAULT NULL,
  `salary` float DEFAULT NULL,
  PRIMARY KEY (`worker_id`,`date_m`,`date_y`),
  KEY `date_m` (`date_m`),
  CONSTRAINT `worker_id3` FOREIGN KEY (`worker_id`) REFERENCES `workers` (`worker_id`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `salaries`
--

LOCK TABLES `salaries` WRITE;
/*!40000 ALTER TABLE `salaries` DISABLE KEYS */;
INSERT INTO `salaries` VALUES ('125436341',3,2020,5,250),('125436341',4,2020,10,500),('125436341',5,2020,5,250),('353253646',3,2020,10,500),('353253646',4,2020,10,500),('353253646',5,2020,5,250),('355647686',3,2020,20,1000),('355647686',4,2020,10,500),('355647686',5,2020,5,250),('378829566',3,2020,10,500),('378829566',4,2020,10,500),('378829566',5,2020,5,250);
/*!40000 ALTER TABLE `salaries` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `transaction_group_id`
--

DROP TABLE IF EXISTS `transaction_group_id`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `transaction_group_id` (
  `group_id` int NOT NULL,
  `transaction_id` int NOT NULL,
  `quantity` int NOT NULL,
  PRIMARY KEY (`group_id`,`transaction_id`),
  KEY `transaction_id2_idx` (`transaction_id`),
  CONSTRAINT `group_id3` FOREIGN KEY (`group_id`) REFERENCES `book_group_id` (`group_id`) ON DELETE CASCADE ON UPDATE CASCADE,
  CONSTRAINT `transaction_id2` FOREIGN KEY (`transaction_id`) REFERENCES `transactions` (`transaction_id`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `transaction_group_id`
--

LOCK TABLES `transaction_group_id` WRITE;
/*!40000 ALTER TABLE `transaction_group_id` DISABLE KEYS */;
INSERT INTO `transaction_group_id` VALUES (3,1,1),(3,7,1),(3,12,1),(4,2,1),(5,8,1),(7,8,1),(7,9,1),(8,3,1),(8,4,1),(9,6,1),(12,7,2),(14,10,1),(14,99,1),(15,12,1),(16,100,1),(17,101,1);
/*!40000 ALTER TABLE `transaction_group_id` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `transactions`
--

DROP TABLE IF EXISTS `transactions`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `transactions` (
  `transaction_id` int NOT NULL AUTO_INCREMENT,
  `transaction_cost` float NOT NULL,
  `delivery_cost` float DEFAULT NULL,
  `payment_method` varchar(45) NOT NULL,
  `costumer_id` varchar(45) NOT NULL,
  `worker_id` varchar(45) NOT NULL,
  `t_date` date NOT NULL,
  PRIMARY KEY (`transaction_id`),
  KEY `costumer_id5_idx` (`costumer_id`),
  KEY `worker_id_idx` (`worker_id`),
  CONSTRAINT `costumer_id5` FOREIGN KEY (`costumer_id`) REFERENCES `costumers` (`costumer_id`) ON DELETE CASCADE ON UPDATE CASCADE,
  CONSTRAINT `worker_id` FOREIGN KEY (`worker_id`) REFERENCES `workers` (`worker_id`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB AUTO_INCREMENT=102 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `transactions`
--

LOCK TABLES `transactions` WRITE;
/*!40000 ALTER TABLE `transactions` DISABLE KEYS */;
INSERT INTO `transactions` VALUES (1,40,15,'credit','234535678','125436341','2020-07-13'),(2,35,15,'cerdit','325754635','125436341','2019-01-13'),(3,80,15,'credit','346478432','125436341','2019-10-13'),(4,250,60,'credit','346547756','355647686','2019-10-19'),(5,33.5,15,'bit','346673167','355647686','2017-12-03'),(6,29,35,'bit','457457547','355647686','2020-04-19'),(7,150,0,'transfer','485929344','378829566','2019-05-16'),(8,100,45,'transfer','547856743','378829566','2019-05-11'),(9,55,0,'credit','774564574','353253646','2019-03-28'),(10,50,15,'bit','774564574','353253646','2019-09-06'),(12,60,77,'bit','234535678','353253646','2019-09-28'),(99,22,12,'credit','547856743','353253646','2019-09-16'),(100,60,0,'credit','547856743','353253646','2019-10-27'),(101,50,0,'credit','654715246','353253646','2019-12-29');
/*!40000 ALTER TABLE `transactions` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `worker_cellphones`
--

DROP TABLE IF EXISTS `worker_cellphones`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `worker_cellphones` (
  `worker_id` varchar(45) NOT NULL,
  `cellphone` varchar(45) NOT NULL,
  PRIMARY KEY (`cellphone`),
  KEY `worker_id2_idx` (`worker_id`),
  CONSTRAINT `worker_id2` FOREIGN KEY (`worker_id`) REFERENCES `workers` (`worker_id`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `worker_cellphones`
--

LOCK TABLES `worker_cellphones` WRITE;
/*!40000 ALTER TABLE `worker_cellphones` DISABLE KEYS */;
INSERT INTO `worker_cellphones` VALUES ('125436341','0526724859'),('214214214','0532432552'),('235235526','0572354223'),('236876315','0532532523'),('353253646','0535235235'),('355647686','0515905034'),('378829566','0591312436'),('436575832','0503526345'),('794572352','0579235457'),('956365745','0511346774');
/*!40000 ALTER TABLE `worker_cellphones` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `workers`
--

DROP TABLE IF EXISTS `workers`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `workers` (
  `worker_id` varchar(45) NOT NULL,
  `f_name` varchar(45) NOT NULL,
  `l_name` varchar(45) NOT NULL,
  `city` varchar(45) NOT NULL,
  `street` varchar(45) NOT NULL,
  `house_num` int NOT NULL,
  `start_date` date NOT NULL,
  `end_date` date DEFAULT NULL,
  PRIMARY KEY (`worker_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `workers`
--

LOCK TABLES `workers` WRITE;
/*!40000 ALTER TABLE `workers` DISABLE KEYS */;
INSERT INTO `workers` VALUES ('125436341','ran','boker','holon','gardom',6,'2020-01-01',NULL),('214214214','mark','shagal','tel aviv','golomb',78,'2018-01-01','2018-05-01'),('235235526','michal','ronen','herzeliya','fabrigat',54,'2018-04-01','2018-12-01'),('236876315','rachel','cohen','tel aviv','grfen',12,'2017-10-01','2018-01-01'),('353253646','yaron','asher','savyon','bedner',34,'2019-12-23',NULL),('355647686','eyal','golan','givatyim','ben goryon',13,'2018-06-12',NULL),('378829566','cohen','raz','rehovot','zalman',3,'2020-04-18',NULL),('436575832','bibi','netanyaho','ramat gan','bialik',84,'2019-03-01','2020-02-02'),('794572352','yarden','biran','bat yam','noah',2,'2016-05-05','2017-05-05'),('956365745','shuki','zikri','yeroshalim','zabotinski',5,'2018-09-09','2018-10-09');
/*!40000 ALTER TABLE `workers` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2020-08-05 19:56:18
