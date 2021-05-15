#!/bin/bash
set -e




if [ ! -d ~/.config/rox_sourceforge_net/MIME-types ]; then
    mkdir -p ~/.config/rox_sourceforge_net/MIME-types
fi
cat > ~/.config/rox_sourceforge_net/MIME-types/shellscript <<\EOF
#!/bin/bash
exec vim "$@"
EOF


if [ ! -d ~/.config/rox_sourceforge_net/MIME-types ]; then
    mkdir -p ~/.config/rox_sourceforge_net/MIME-types
fi
cat > ~/.config/rox_sourceforge_net/MIME-types/text <<\EOF
#!/bin/bash
exec gedit "$@"
EOF


if [ ! -d ~/.config/rox_sourceforge_net/MIME-types ]; then
    mkdir -p ~/.config/rox_sourceforge_net/MIME-types
fi
cat > ~/.config/rox_sourceforge_net/MIME-types/smplayer <<\EOF
#!/bin/bash
exec smplayer "$@"
EOF


cd ~/.config/rox_sourceforge_net/MIME-types
chmod 755 *


