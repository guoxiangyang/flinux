#pragma once

#include <common/stat.h>
#include <common/dirent.h>
#include <common/poll.h>
#include <common/select.h>
#include <common/uio.h>
#include <fs/file.h>

#include <stdint.h>

#define PATH_MAX			4096
#define MAX_FD_COUNT		1024
#define MAX_SYMLINK_LEVEL	8

void vfs_init();
void vfs_reset();
void vfs_shutdown();
int vfs_store_file(struct file *f, int cloexec);

int vfs_open(const char *pathname, int flags, int mode, struct file **f);
void vfs_close(int fd);
struct file *vfs_get(int fd);
void vfs_ref(struct file *f);
void vfs_release(struct file *f);
