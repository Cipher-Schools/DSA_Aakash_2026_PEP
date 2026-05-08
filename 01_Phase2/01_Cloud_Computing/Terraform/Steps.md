What Happens When You Run Terraform?
- Step 1
```
terraform init
```
Downloads: AWS provider plugin

- Step 2
```
terraform plan
```

Shows: what Terraform WILL create

Nothing created yet.

- Step 3
```
terraform apply
```

Actually creates EC2 instance.

Terraform sends API calls to AWS.