/* vi:set ts=4 sw=4 expandtab:
 *
 * Copyright 2016, Chris Leishman (http://github.com/cleishm)
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
#ifndef NEO4J_RENDER_H
#define NEO4J_RENDER_H

#include "neo4j-client.h"

#define NEO4J_FIELD_BUFFER_INITIAL_CAPACITY 1024

uint_fast32_t normalize_render_flags(uint_fast32_t flags);

typedef enum
{
    HLINE_TOP,
    HLINE_MIDDLE,
    HLINE_BOTTOM
} hline_position_t;

typedef enum
{
    HORIZONTAL_LINE,
    VERTICAL_LINE,
    TOP_LEFT_CORNER,
    TOP_MIDDLE_CORNER,
    TOP_RIGHT_CORNER,
    MIDDLE_LEFT_CORNER,
    MIDDLE_MIDDLE_CORNER,
    MIDDLE_RIGHT_CORNER,
    BOTTOM_LEFT_CORNER,
    BOTTOM_MIDDLE_CORNER,
    BOTTOM_RIGHT_CORNER
} border_line_t;

int render_border_line(FILE *stream, border_line_t line_type,
        uint_fast32_t flags);

int render_hrule(FILE *stream, unsigned int ncolumns,
        unsigned int *widths, hline_position_t position,
        bool undersize, uint_fast32_t flags);

typedef int (*render_row_callback_t)(
        void *cdata, FILE *stream, unsigned int n, unsigned int width);
int render_row(FILE *stream, unsigned int ncolumns,
        unsigned int *widths, bool undersize, uint_fast32_t flags,
        render_row_callback_t callback, void *cdata);

#endif/*NEO4J_RENDER_H*/
