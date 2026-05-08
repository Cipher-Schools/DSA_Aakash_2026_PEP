terraform {
  required_providers {
    aws = {
      source  = "hashicorp/aws"
      version = "~> 6.0"
    }
  }
}

provider "aws" {
  region = "us-east-1"
}

# -----------------------------
# Security Group
# Allows SSH access on port 22
# -----------------------------
resource "aws_security_group" "ssh_access_new" {
  name        = "allow_ssh"
  description = "Allow SSH inbound traffic"

  ingress {
    description = "SSH Access"
    from_port   = 22
    to_port     = 22
    protocol    = "tcp"

    cidr_blocks = ["0.0.0.0/0"]
  }

  egress {
    from_port   = 0
    to_port     = 0
    protocol    = "-1"

    cidr_blocks = ["0.0.0.0/0"]
  }

  tags = {
    Name = "allow_ssh"
  }
}

# -----------------------------
# EC2 Instance
# -----------------------------
resource "aws_instance" "app_server_new2" {

  ami           = "ami-091138d0f0d41ff90"
  instance_type = "t3.micro"

  # Existing AWS Key Pair Name
  key_name = "cloud_key_dev"

  vpc_security_group_ids = [
    aws_security_group.ssh_access.id
  ]

  tags = {
    Name = "Terraform_Demo4"
  }
}

# -----------------------------
# Output Public IP
# -----------------------------
output "public_ip" {
  value = aws_instance.app_server.public_ip
}