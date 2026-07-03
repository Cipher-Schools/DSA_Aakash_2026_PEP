# Project: Highly Available Three-Tier AWS Infrastructure with Terraform

## Project Description

Build a **Highly Available Three-Tier AWS Infrastructure** using **Terraform** by provisioning all required AWS resources through Infrastructure as Code (IaC).

The infrastructure should include a **custom VPC**, **public and private subnets across multiple Availability Zones**, **Internet Gateway**, **NAT Gateway**, **route tables**, **Application Load Balancer**, **EC2 instances**, and an **Amazon RDS MySQL database**. The entire environment should be deployed and managed using Terraform, following AWS networking and security best practices.

---

## Project Requirements

1. Create a **custom VPC** with an appropriate CIDR block.

2. Provision networking resources including:

   * Internet Gateway
   * Public and Private Route Tables
   * Public and Private Subnets across at least **two Availability Zones**
   * NAT Gateway for outbound internet access from private subnets

3. Configure Route Tables and associate them with the appropriate subnets.

4. Launch the infrastructure using Terraform:

   * Bastion Host in a Public Subnet
   * Web Application EC2 Instance(s) in Private Subnet(s)
   * Amazon RDS MySQL Instance in Private Subnet(s)

5. Create an **Application Load Balancer (ALB)** to distribute incoming traffic to the Web Application instances.

6. Configure **Security Groups** to allow only the required communication between:

   * Internet → Load Balancer
   * Bastion Host → Web Application
   * Web Application → RDS Database

7. Store all infrastructure configuration in **Terraform (.tf)** files following a modular and well-structured approach.

8. Verify that:

   * Infrastructure is created successfully using Terraform.
   * Web application is accessible through the Load Balancer.
   * Bastion Host can securely access the private EC2 instance.
   * Web Application can successfully connect to the MySQL database.
   * Resources can be destroyed cleanly using `terraform destroy`.

---

## GitHub Repository Must Include

* Complete Terraform source code.
* `README.md` containing:

  * Project overview
  * Architecture diagram
  * AWS services used
  * Folder structure
  * Prerequisites
  * Terraform initialization and deployment steps
  * Variables and outputs explanation
  * Deployment verification steps
  * Screenshots of:
    * Terraform files
    * Terraform Apply Output
    * VPC Dashboard
    * Subnets
    * Route Tables
    * Internet Gateway
    * NAT Gateway
    * Security Groups
    * EC2 Instances
    * Application Load Balancer
    * Target Group Health Check
    * Amazon RDS Instance
    * Web Application running through the Load Balancer
  * Challenges or issues encountered during implementation

---

## Expected Outcome

At the end of this project, the complete AWS infrastructure should be provisioned using **Terraform** with a single deployment workflow. The solution should provide a secure, scalable, and highly available three-tier architecture where the web application runs in private subnets behind an Application Load Balancer, the database remains isolated in private subnets, and infrastructure can be recreated or removed consistently using Infrastructure as Code.

## Project architecture

![02_Project](../images/VPC.png)