# Hello World C++ REST Demo

This is a simple C++ REST service built and packaged in a container. This app uses https://github.com/corvusoft/restbed to provide a C++ based REST-ful api.

This app may be built using either Podman or OpenShift.


## Podman
Follow these steps to build and run this with Podman

```
git clone https://github.com/david-rh/cpprest.git
cd cpprest
podman build -t hellocpp .
podman run --name hellocpp -p 9080:9080 hellocpp
```

In another terminal, test with the following command
```
curl -d "SomeText" http://localhost:9080/resource
```

## OpenShift

Follow these steps to build and run this with OpenShift

```
oc new-project hellocpp
oc new-app https://github.com/david-rh/cpprest.git
```


