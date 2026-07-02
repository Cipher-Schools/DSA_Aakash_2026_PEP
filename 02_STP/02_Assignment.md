# **Assignment 02** : AWS S3 Static Website Hosting with Versioning & Lifecycle Management

## Submission Requirements

Before submitting, make sure:

* GitHub repository is **complete and public**
* Static website is **properly deployed using S3**
* S3 bucket remains **active untill assignment evaluation complete.**
* All screenshots clearly show your **AWS username**

---

## Assignment Objective

In this assignment, you will work with Amazon Web Services S3 (Simple Storage Service) to understand:

* Object storage fundamentals
* Static website hosting
* Version control in storage
* Storage cost optimization using lifecycle rules

---

## Assignment Description

### 1. Create an S3 Bucket

* Create a new S3 bucket
* Bucket name must be **globally unique**

---

### 2. Enable Versioning

* Enable **Versioning** on the bucket
* Upload a file (e.g., `index.html`)
* Modify the file and upload again

👉 The goal: You should have **multiple versions of the same file**

---

### 3. Deploy Static Website

* Enable **Static Website Hosting** in bucket properties

---

### 4. Define Lifecycle Rules

* Create lifecycle rules for objects in the bucket
* Example rules:

  * Transition objects to cheaper storage (like Standard-IA)
  * Delete old versions after certain days

👉 The goal: Understand **cost optimization + storage automation**

---

## **GitHub Repository Must Include**

Your repo should contain:

* Complete static website code (HTML, CSS, JS)
* A properly written `README.md` having :
    * **Name**
    * **Registration Number**
    * Deployed Website Link (S3 URL)
    * **Screenshots (Compulsory)**
        1. S3 Bucket with uploaded files visible
        2. Versioning view showing multiple versions of a file
        3. Lifecycle rule configuration
    * Any challenges or issues faced during the assignment

👉 In ALL screenshots:
Your **AWS username must be clearly visible**. If it’s not visible, it won’t be evaluated.

---

## **Important Notes**

* Your S3 website link must remain active till **assignment evaluation complete.**