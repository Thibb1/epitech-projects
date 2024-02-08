# syntax=docker/dockerfile:1

FROM node
EXPOSE $PORT
WORKDIR /app
COPY ["package.json", "package-lock.json*", "./"]
RUN npm install
COPY . .
ENTRYPOINT npm start