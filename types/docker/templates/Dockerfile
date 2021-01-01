FROM alpine AS build

WORKDIR /usr/build

COPY ./app .

RUN apk add --no-cache build-base \
  && gcc -o main main.c

FROM alpine

WORKDIR /usr/src/app/

COPY --from=build /usr/build/main .

CMD ["./main"]

