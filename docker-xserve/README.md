# Docker FWBuilder

## Build on your own

```bash
APP_VERSION=dev docker build --build-arg APP_VERSION=$APP_VERSION -t fwbuilder .
```
## For Dev

```bash
docker run -e "DISPLAY=host.docker.internal:0" -v /tmp/.X11-unix:/tmp/.X11-unix  --rm -ti --net host ubuntu:focal
```

## How to run

Connecting a container to a host's X server for display

```bash
xhost +localhost     
docker run -e "DISPLAY=host.docker.internal:0" -v /tmp/.X11-unix:/tmp/.X11-unix --rm -ti --net host fwbuilder:latest
```

## To do

  - write an entrypoint for flexible UID and GID
  - use travis for CI