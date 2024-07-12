CIE1931_CURVE = yes
I2C_DRIVER_REQUIRED = yes

# project specific files
#SRC += keyboards/wilba_tech/wt_main.c \
#       keyboards/wilba_tech/wt_rgb_backlight.c \
#       quantum/color.c \
#       drivers/led/issi/is31fl3731.c

# disable wilbatech rgb impl (above), enable base impl
RGB_MATRIX_ENABLE = yes