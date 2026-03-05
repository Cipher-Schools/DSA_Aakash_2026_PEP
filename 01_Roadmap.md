# Cloud Computing Roadmap

## Topics Covered

1. Fundamentals
2. Cloud Platforms
3. Containerization and Orchestration
4. Python Scripting
5. Infrastructure as Code
6. CI/CD Pipelines
7. Observability, Monitoring, and Logging

---

# 1. Fundamentals

## A. Introduction to DevOps, Cloud, and SDLC

* What is DevOps and Cloud Computing?
* Why do they exist?
* Relationship between DevOps and Cloud Computing

### SDLC Concepts

* What is the Software Development Lifecycle (SDLC)?
* Where DevOps and Cloud Computing fit in the SDLC process
* How DevOps and Cloud help accelerate software delivery

---

## B. Linux

* What is Linux?
* Linux vs Windows
* Why we learn Linux
* Linux commands / shell commands
* Operating system processes and permissions

  * `ps`, `kill`, `chmod`, `chown`
* Linux Virtual Machines
* Package management

  * `apt`, `vim`
* Bash CLI
* Bash scripting basics

---

## C. Networking and Security Concepts

### How Computers Interact with Each Other

* OSI Model
* TCP/IP Model
* IP addresses
* Subnetting
* DNS
* DHCP

### Networking Protocols

* HTTP
* HTTPS
* SSH
* FTP

### Network Troubleshooting Concepts

* Common networking issues
* Firewall configuration
* Proxy servers

### How the Internet Works

* HTTP vs HTTPS
* Client–server model
* Request–response cycle

### Good to Have

* Load balancers
* Caching servers

---

## D. Version Control Systems – Git / GitHub

* Git commands
* Concept of branching
* Merging and merge conflict resolution
* Working with remote repositories

---

# 2. Cloud Platforms

Cloud platforms include:

* AWS
* Azure
* GCP
* Many others

### Our focus will be on **AWS**

---

## A. Fundamentals of Cloud

* What is cloud computing?
* Why we use cloud computing
* Benefits and trade-offs of cloud platforms
* On-premises vs cloud

### Cloud Service Models

* IaaS
* PaaS
* SaaS

### Cloud Deployment Models

* Public
* Private
* Hybrid
* Multi-cloud

### Cloud Concepts

* Regions and availability zones
* Scalability and high availability
* Shared responsibility model

### Cloud Economics and Cost Optimization

* Why cost matters
* Pay-as-you-go model

---

## B. Which Cloud Service Solves Which Problem

### Compute Services

* EC2 — AWS
* Lambda — AWS

### Storage Services

* S3 — AWS
* Blob Storage — Azure

### Networking Services

* VPC (Virtual Private Cloud)
* Subnets
* Security Groups / NSGs
* Elastic Load Balancing — AWS
* Route 53 — AWS

### Database Services

* RDS — AWS (SQL databases)
* DynamoDB — AWS (NoSQL databases)

### IAM (Identity and Access Management)

* Used to create and manage users
* Assign permissions and roles

### Scaling Services

* Auto Scaling Groups (ASG)

### Container-Related Services

* ECR, ECS, EKS — AWS
* AKS — Azure
* GKE — GCP

### Monitoring and Observability Services

* Amazon CloudWatch

### Content Delivery Network (CDN)

* Amazon CloudFront

### Additional Cloud Services

* CI/CD services
* Surveillance services
* Compliance and security services
* Automation services

---

## With Any Cloud Provider We Achieve These Core Tasks

* Configure and manage servers and data
  **EC2, S3, RDS**

* Manage users, groups, and roles
  **IAM**

* Set up and manage isolated networks
  **VPC**

---

# 3. Containerization and Orchestration

## A. Microservices and Containerization – Docker

* Docker fundamentals
* Why we use Docker
* Docker vs Virtual Machines
* Overview of virtualization and containerization
* Docker images and container management
* Docker commands
  `run`, `ps`, `build`, etc.
* Writing Dockerfiles

---

## B. Orchestration and Management – Kubernetes

* Kubernetes architecture
* Creating a cluster in Kubernetes
* Kubernetes commands
  `apply`, `build`, `delete`, etc.
* Pods
* StatefulSets
* DaemonSets

---

# 4. Python Scripting

* Introduction to Python scripting
* Writing automation scripts
* Using Python for infrastructure automation

---

# 5. Infrastructure as Code (IaC)

### Tools

* Infrastructure provisioning
  **Terraform (primary focus)** or **Pulumi**

* Infrastructure configuration
  **Ansible**

---

### Terraform Concepts

* Providers
* State management
* State locking
* Provisioners
* Workspaces
* Modules
* Importing resources

---

# 6. CI/CD Pipelines

For any application development process there are four major steps:

1. Write the code
2. Build the code
3. Test the code
4. Deploy the code

### Automation with CI/CD

Tools:

* Jenkins
* GitHub Actions

---

# 7. Observability, Monitoring, and Logging

Tools:

* Grafana (primary focus)
* Prometheus

---