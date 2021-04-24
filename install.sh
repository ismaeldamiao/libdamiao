#!/bin/bash

if [ "${PREFIX}" == "/data/data/com.termux/files/usr" ]; then
   DIR="${PREFIX}/share/newc"
else
   DIR="${HOME}/.config/newc"
fi

[ -d "${DIR}" ] && rm -R "${DIR}"
mkdir -p "${DIR}"
cp -R "./include" "${DIR}"
cp "main.c" "${DIR}"

# Script
if [ "${PREFIX}" == "/data/data/com.termux/files/usr" ]; then
   bin="${PREFIX}/bin/newc"
else
   [ -d "${HOME}/bin" ] || mkdir -p "${HOME}/bin"
   bin="${HOME}/bin/newc"
fi
cat > "${bin}" << EOF
#!/bin/bash
[ "\$#" -lt "1" ] && cp -R "${DIR}/"* "\$(pwd)" || \
{ [ -d "\$1" ] || mkdir -p "\$1"; cp -R "${DIR}/"* "\$1"; }
exit 0
EOF
chmod 700 "${bin}"

exit 0
