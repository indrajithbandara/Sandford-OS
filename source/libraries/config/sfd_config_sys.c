typedef struct {
    int max_line_len;
} SYS_CONFIG;

SYS_CONFIG *SFD_SYS_CONFIG;

/* Default Config */
int sfd_config_init() {
    SFD_SYS_CONFIG = malloc(sizeof(SYS_CONFIG));
    SFD_SYS_CONFIG->max_line_len = 509;
}
