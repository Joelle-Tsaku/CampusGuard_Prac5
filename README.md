# CampusGuard_Prac5
 An emergency-response coordination platform for a large university campus


Docker:
    Build and run the application using:

        docker compose up --build

    This should build the docker image, compile the c++ application using the makefile, start the container and run the CampusGuard demonstration.  

The application can also be tested locally by running:
    build: 
        make clean
        make
    run:
        ./campus_guard


