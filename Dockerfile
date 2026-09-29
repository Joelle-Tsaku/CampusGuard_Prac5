FROM gcc:latest

WORKDIR /app

COPY . .

RUN make clean && make 

CMD ["./campus_guard"]
