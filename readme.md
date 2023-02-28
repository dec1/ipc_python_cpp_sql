# Inter-Process Communication via Tcp Sockets and (SQL) Database

##### Prolog
This document is markdown format and best viewed using a markdown capable viewer, such as 
_pycharm_ or _visual studio code_. Alternatively copy/paste into an online markdown viewer 
such as https://dillinger.io

### Introduction
This project demonstrates the simultaneous instantaneous and execution of multiple instances of applications written in C++,
each of which can perform read/write on a database. 

#### Implementation 
- *Data Store*: The actual backing store is by default a MySQL database but is dependency injected to promote modularity,
testability and extensibility.  In the c++ unit tests the database backing store is mocked out with other backing stores (in-file and in-memory).
- *Socket based IPC*: To facilitate inter-process communication, the instances also listen for tcp/ip socket connections (on a unique port),
- and allow themselves to be "scripted" via any messages thus received.
- *Python client*: A python project and test framework (pytest) scripts the creation, communication with, and cleanup of the c++ instances. 
- *Concurrent execution*: Use has also been made of concurrent execution (asyncio) to demonstrate the efficient management of network-bound io eg. any number of 
c++ instances can be started, and their tcp servers ready to receive messages, in (almost) constant (same as for single instance) time. 

#### Testing 
- C++ unit tests, using the Qt test framework, and cmake's support for testing
- Python client uses a test framework (*pytest*) to (asynchronously) assert that the behaviour and reads/writes of the c++ instances is as expected

#### CI
A docker image was created using the dockefile in the ci/docker directory, and uploaded to the gitlab container registry, for use in the ci pipeine

## Prerequisites
- Qt 6
- CMake >= 3.15
- Python >= 3.8
