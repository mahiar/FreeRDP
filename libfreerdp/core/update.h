/**
 * FreeRDP: A Remote Desktop Protocol Implementation
 * Update Data PDUs
 *
 * Copyright 2011 Marc-Andre Moreau <marcandre.moreau@gmail.com>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef __UPDATE_H
#define __UPDATE_H

#include "rdp.h"
#include "orders.h"
#include <freerdp/types.h>
#include <freerdp/update.h>
#include <freerdp/freerdp.h>
#include <freerdp/utils/stream.h>

#define UPDATE_TYPE_ORDERS		0x0000
#define UPDATE_TYPE_BITMAP		0x0001
#define UPDATE_TYPE_PALETTE		0x0002
#define UPDATE_TYPE_SYNCHRONIZE		0x0003

#define BITMAP_COMPRESSION		0x0001
#define NO_BITMAP_COMPRESSION_HDR	0x0400

rdpUpdate* update_new(rdpRdp* rdp);
void update_free(rdpUpdate* update);
void update_free_bitmap(BITMAP_UPDATE* bitmap_update);
void update_reset_state(rdpUpdate* update);

BOOL update_read_bitmap(rdpUpdate* update, STREAM* s, BITMAP_UPDATE* bitmap_update);
BOOL update_read_palette(rdpUpdate* update, STREAM* s, PALETTE_UPDATE* palette_update);
BOOL update_recv_play_sound(rdpUpdate* update, STREAM* s);
BOOL update_recv_pointer(rdpUpdate* update, STREAM* s);
BOOL update_recv(rdpUpdate* update, STREAM* s);

BOOL update_read_pointer_position(STREAM* s, POINTER_POSITION_UPDATE* pointer_position);
BOOL update_read_pointer_system(STREAM* s, POINTER_SYSTEM_UPDATE* pointer_system);
BOOL update_read_pointer_color(STREAM* s, POINTER_COLOR_UPDATE* pointer_color);
BOOL update_read_pointer_new(STREAM* s, POINTER_NEW_UPDATE* pointer_new);
BOOL update_read_pointer_cached(STREAM* s, POINTER_CACHED_UPDATE* pointer_cached);

BOOL update_read_refresh_rect(rdpUpdate* update, STREAM* s);
BOOL update_read_suppress_output(rdpUpdate* update, STREAM* s);

void update_register_server_callbacks(rdpUpdate* update);
void update_register_client_callbacks(rdpUpdate* update);

#endif /* __UPDATE_H */
