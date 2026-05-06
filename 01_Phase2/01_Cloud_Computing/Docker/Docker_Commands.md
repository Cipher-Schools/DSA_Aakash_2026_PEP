# Docker genral commands

- usermod -aG docker ubuntu // to give access of docker froup to the normal user

- docker ps

- docker ps -a

- fetch and run a image form docker hun

docker run --name container-App -p 8080:80 -d nginx











## Process

1. Take any web application for example from tooplate

```
wget https://templatemo.com/tm-zip-files-2020/templatemo_522_venue.zip
```

2. install 'unzip' if not available

3. Build **Artifacts** of your WebApp (unziped)
```
tar czvf nano.tar.gz *
```

4. Write the docker file
```
vim Dockerfile
```

5. Build the image for your application
```
docker build -t <yourImgname> .

6. Check for your docker images
```
docker images
```

7. Run your app img using new container at specific port

8. Push your img on DockerHub
- First Create your account on DockerHub
- log in CLI
```
docker login -u <username>
```
- push your image
```
docker push <your img name>
```