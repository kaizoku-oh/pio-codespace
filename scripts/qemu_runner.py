Import("env")
import os

def run_qemu(source, target, env):
    firmware = os.path.join(env.subst("$BUILD_DIR"), "firmware.elf")
    print("Running QEMU with: ", firmware)
    os.system(f"qemu-system-arm -M stm32-p103 -nographic -kernel {firmware} -serial stdio")

env.AddPostAction("buildprog", run_qemu)
