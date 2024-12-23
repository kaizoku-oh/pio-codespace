# Use an official Python image as a base
FROM python:3.11-slim

# Set the working directory in the container
WORKDIR /workspace

# Install required system dependencies
RUN apt update && apt install -y \
    curl \
    git \
    g++ \
    cmake \
    build-essential \
    libusb-1.0-0-dev \
    python3-pip \
    && rm -rf /var/lib/apt/lists/*

# Install PlatformIO as root
RUN curl -fsSL -o get-platformio.py https://raw.githubusercontent.com/platformio/platformio-core-installer/master/get-platformio.py \
    && python3 get-platformio.py \
    && rm get-platformio.py

# Add PlatformIO's binary directory to PATH for root (default user)
ENV PATH="/root/.platformio/penv/bin:${PATH}"

# Set the working directory to /workspace
WORKDIR /workspace

# Copy the current directory contents into the container at /workspace
COPY . /workspace

# Define the default command to run PlatformIO
ENTRYPOINT ["platformio"]
CMD ["--help"]
