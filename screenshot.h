#ifndef SCREENSHOT_H
#define SCREENSHOT_H

#include <stdint.h>
#include <stdbool.h>
#include <wayland-client.h>

struct screenshot {
    struct wl_buffer *wl_buffer;
    void *data;
    int32_t width, height, stride;
    uint32_t flags;
    enum wl_shm_format format;
    struct output *output;
    bool ready;
    struct wl_list link;
};

extern struct wl_list screenshots;

struct screenshot *take_screenshot(struct output *output);
void screenshot_cleanup(struct screenshot *screenshot);

#endif /* #ifndef SCREENSHOT_H */

