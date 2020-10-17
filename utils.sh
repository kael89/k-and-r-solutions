COLOR_RESET=0
COLOR_RED=31
COLOR_GREEN=32
COLOR_YELLOW=33
COLOR_CYAN=36

function ansi_color() {
    echo -e "\033[$1m"
}

function log_with_color() {
    echo -e "$(ansi_color $2)$1$(ansi_color $COLOR_RESET)"
}

function log_error() {
    log_with_color "$1" $COLOR_RED
}

function log_warn() {
    log_with_color "$1" $COLOR_YELLOW
}

function log_success() {
    log_with_color "$1" $COLOR_GREEN
}

function log_info() {
    log_with_color "$1" $COLOR_CYAN
}
