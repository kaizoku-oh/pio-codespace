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

# Download and install PlatformIO using the specified commands
RUN curl -fsSL -o get-platformio.py https://raw.githubusercontent.com/platformio/platformio-core-installer/master/get-platformio.py \
    && python3 get-platformio.py \
    && rm get-platformio.py

# Add PlatformIO's binary directory to PATH
ENV PATH="/root/.platformio/penv/bin:${PATH}"

# Create a non-root user for security
RUN useradd -ms /bin/bash pio_user
USER pio_user

# Copy the current directory contents into the container at /workspace
COPY . /workspace

# Define the default command to run PlatformIO
ENTRYPOINT ["platformio"]
CMD ["--help"]
