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
    libglib2.0-dev \
    libpixman-1-dev \
    pkg-config \
    ninja-build \
    ca-certificates \
    libusb-1.0-0-dev \
    python3-pip \
    && rm -rf /var/lib/apt/lists/*

# Clone and build QEMU for STM32
RUN git clone --depth 1 https://github.com/beckus/qemu_stm32.git /opt/qemu_stm32 \
    && cd /opt/qemu_stm32 \
    && ./configure --target-list=arm-softmmu --disable-werror \
    && make -j$(nproc) \
    && make install

# Optional: Clean up source to reduce image size
RUN rm -rf /opt/qemu_stm32

# Verify if Qemu is installed and added to path
RUN qemu-system-arm --version

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
ENTRYPOINT ["pio"]
CMD ["--help"]
