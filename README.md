# 🚀 GitHub Codespace for PlatformIO

[![GitHub release](https://img.shields.io/github/v/release/kaizoku-oh/pio-codespace)](https://github.com/kaizoku-oh/pio-codespace/releases)
[![GitHub issues](https://img.shields.io/github/issues/kaizoku-oh/pio-codespace)](https://github.com/kaizoku-oh/pio-codespace/issues)
[![License: MIT](https://img.shields.io/badge/License-MIT-blue.svg)](https://github.com/kaizoku-oh/pio-codespace/blob/main/LICENSE)

## ToDo

It seems like the submodules were not properly added to the repository.

Add each submodule:

```bash
git submodule add https://github.com/ARMmbed/mbedtls ext/mbedtls

git submodule add https://github.com/cypresssemiconductorco/psoc6pdl.git boot/cypress/libs/pdl/psoc6pdl

git submodule add https://github.com/cypresssemiconductorco/retarget-io.git boot/cypress/libs/retarget-io

git submodule add https://github.com/cypresssemiconductorco/core-lib.git boot/cypress/libs/core-lib

git submodule add https://github.com/cypresssemiconductorco/psoc6hal.git boot/cypress/libs/psoc6hal

git submodule add https://github.com/cypresssemiconductorco/cy-mbedtls-acceleration.git boot/cypress/libs/cy-mbedtls-acceleration

git submodule add https://github.com/oyvindronningstad/cddl_gen.git ext/cddl_gen
```

Commit the changes:

```bash
git commit -m "Add submodules"
```

Initialize and update the submodules:

```bash
git submodule update --init --recursive
```

This should properly add the submodules to the repository and clone them into the specified directories.
