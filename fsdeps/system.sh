# Intended for sourcing by other shell scripts
# This file is automatically generated by fs-package

case "`uname`" in
    Linux*)  SYSTEM_OS=Linux;;
    Darwin*) SYSTEM_OS=macOS;;
    MINGW*)  SYSTEM_OS=Windows;;
    *)       SYSTEM_OS=Unknown;;
esac

case "`uname -m`" in
    x86_64*)  SYSTEM_ARCH=x86-64;;
    arm64*)   SYSTEM_ARCH=ARM64;;
    armv7l*)  SYSTEM_ARCH=ARM;;
    *)        SYSTEM_ARCH=Unknown;;
esac

# FIXME: Deprecated alias
SYSTEM=$SYSTEM_OS
