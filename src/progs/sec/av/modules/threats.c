/*
 * threat_detection.c - This file is part of Sandford AV, a simple anti-virus
 * and anti-malware tool for Sandford OS.
 * Copyright 2016, 2017 Brian Millar <brianmillar@protonmail.ch>
 *
 * Sandford AV is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Sandford AV is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Sandford AV.  If not, see <http://www.gnu.org/licenses/>.
 */

char *detect_threat(FILE*, char*);

char *detect_threat(FILE *f, char *type) {
    if (strcmp(type, "JPEG Image File         ") == 0)
        return scan_JPEG(f);
    return NULL;
}
