# **Assignment 03 : AWS RDS Deployment and Secure Database Access using SSH**

## **Submission Requirements**

Before submitting, make sure:

* GitHub repository is **complete and public**
* RDS instance remains **active untill assignment evaluation complete.**
* All screenshots clearly show your **AWS username**

---

## **Assignment Objective**

In this assignment, you will learn how to:

* Launch a managed relational database using **Amazon RDS**
* Securely access a private database using **SSH**
* Connect to the database from an EC2 instance
* Create a database and verify successful connectivity

---

## **Assignment Description**

### **1. Launch an Amazon RDS Instance**

* Create an Amazon RDS instance.
* You may use **MySQL** or **MariaDB**.
* Configure the instance properly so that it can be accessed only through your EC2 instance.
* **Do not make the RDS instance publicly accessible.**

---

### **2. Launch an EC2 Instance**

* Create an EC2 instance in the **same VPC** as your RDS instance.
* Configure the required Security Groups.
* Use SSH to log in to the EC2 instance.

---

### **3. Connect to the RDS Instance**

From the EC2 instance:

* Install the required database client (if needed).
* Connect to the RDS instance using its endpoint.
* Verify that the connection is successful.

---

### **4. Create an Employee Database**

After successfully connecting to the RDS instance:

* Create a database named `employee_db`.
* Create an `employees` table with the following columns:

| Column Name    | Data Type                         |
| -------------- | --------------------------------- |
| `emp_id`       | INT (Primary Key, Auto Increment) |
| `first_name`   | VARCHAR(50)                       |
| `last_name`    | VARCHAR(50)                       |
| `email`        | VARCHAR(100)                      |
| `department`   | VARCHAR(50)                       |
| `salary`       | DECIMAL(10,2)                     |
| `joining_date` | DATE                              |

* Insert **at least 5 employee records** into the table.
* Execute a `SELECT * FROM employees;` query to verify that the records have been inserted successfully.

---

## **GitHub Repository Must Include**

Your repository should contain:

* A `README.md` file
* SQL file (`employee_db.sql`) containing:

  * Database creation query
  * Table creation query
  * INSERT statements
  * SELECT query
* Any scripts or commands used during the assignment (optional)

---

## **README.md Must Include**

* Name
* Registration Number

### **Screenshots (Compulsory)**

1. RDS instance dashboard
2. EC2 instance dashboard
3. SSH terminal showing successful login into EC2
4. Successful connection from EC2 to the RDS instance
5. SQL terminal showing:

   * Database creation
   * Employees table creation
   * Inserted employee records (`SELECT * FROM employees;`)

👉 **In every AWS Console screenshot, your AWS username must be clearly visible.**

---

## **Challenges Faced**

Mention any challenges you encountered while completing the assignment and how you resolved them.

---

## **Important Notes**

* **Do not enable Public Access for the RDS instance.** The objective is to learn secure database access through an EC2 instance.
* Ensure that your RDS instance remains **active untill assignment evaluation complete.**, as submissions may be verified during this period.

---

This assignment tests your understanding of:

* Amazon RDS
* VPC networking
* Security Groups
* SSH
* Secure database connectivity
* Basic SQL operations
* AWS infrastructure best practices
