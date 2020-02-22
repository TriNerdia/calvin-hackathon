# Application Health Checker

## Problem
Our game studio has a server in the cloud that is hosting a simple website and Minecraft game. As this server is important to our customers, the studio needs a simple tool to monitor and test the health of the server. There is not enough money in the budget right now to purchase an enterprise tool so our developers will need to come up with a solution within 24 hours.

## Requirements
* Monitor different ports on the server
* Be able to run tests against the server to verify health
* Display report in easy-to-read format

## Build
> This application is only supported for Windows 10
* Install vcpkg
* Install libcurl through vcpkg
```
vcpkg install curl
```
```
vcpkg integrate install
```

* Install Visual Studio 2019
* Clone this repository
* Import project solution into Visual Studio 2019
* Run Build Solution command

## Run
* Open Powershell in the Debug folder in the Solution directory
* Run application
```
ConsoleApplication.exe <config file> <test>
```

## Contributors
If you'd like to contribute, please fork the repository and use a feature branch. Pull requests are warmly welcome.