/* sfd_libobj.c - This file is part of Project Sandford, a New Operating System.
 * Copyright 2016, 2017 Brian Millar <brianmillar@protonmail.ch>
 *
 * Project Sandford is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Project Sandford is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Project Sandford.  If not, see <http://www.gnu.org/licenses/>.
 */

typedef struct {
    int x, y, z, w;
} VEC4;

typedef struct {
    int vertc;
    VEC4 *verts;
} FACE;

typedef struct {
    int vertc, facec, texc = 0;
    char *name;
    VEC4 *texs;
    FACE *faces;
} OBJ;

OBJ *sfd_obj_load(char *name) {
    OBJ *obj = malloc(sizeof(OBJ));
    obj->name = "";
    obj->verts = obj->norms = obj->texs = NULL;
    obj->faces = NULL;
    char *buffer = malloc(SFD_MAX_LINE_LEN + 1);
    FILE *file = fopen(name, "r");
    int i, c;
    i = c = 0;
    if (file) {
        while (c != EOF) {
            while ((c = fgetc(file)) != '\n' && c != EOF)
                buffer[i++] = c;
            if (i < SFD_MAX_LINE_LEN) {
                buffer[i] = '\0';
                if (buffer && buffer[0] != '#' && buffer[0] != '\n' && strlen(buffer) != 0) {
                    if (buffer[0] == 'o' && buffer[1] == ' ') {
                        char *name;
                        strtok(buffer, " ");
                        name = strtok(NULL, "\0");
                        obj.name = strdup(name);
                    }
                    else if (buffer[0] == 'v' && buffer[1] == ' ') {
                        VEC4 vert;
                        strtok(buffer, " ");
                        vert.x = (float)atof(strtok(NULL, " "));
                        vert.y = (float)atof(strtok(NULL, " "));
                        vert.z = (float)atof(strtok(NULL, " "));
                        obj.verts = realloc(obj.verts, ++obj.vertc * sizeof(vec4));
                        obj.verts[obj.vertc - 1] = vert;
                    }
                    else if (buffer[0] == 'v' && buffer[1] == 'n' && buffer[2] == ' ') {
                        VEC4 norm;
                        strtok(buffer, " ");
                        norm.x = (float)atof(strtok(NULL, " "));
                        norm.y = (float)atof(strtok(NULL, " "));
                        norm.z = (float)atof(strtok(NULL, " "));
                        obj.norms = realloc(obj.norms, ++obj.normc * sizeof(VEC4));
                        obj.norms[obj.normc - 1] = norm;
                    } else if (buffer[0] == 'v' && buffer[1] == 't' && buffer[2] == ' ') {
                        VEC4 tex;
                        strtok(buffer, " ");
                        tex.x = (float)atof(strtok(NULL, " "));
                        tex.y = (float)atof(strtok(NULL, " "));
                        obj.texs = realloc(obj.texs, ++obj.texc * sizeof(VEC4));
                        obj.texs[model.texc - 1] = tex;
                    } else if (buffer[0] == 'f' && buffer[1] == ' ') {
                        FACE f;
                        VEC4 v;
                        f.verts = NULL;
                        f.vertc = 0;
                        char *token;
                        int j, i = 0;
                        strtok(buffer, " ");
                        while ((token = (strtok(NULL, " ")))) {
                            char *token2 = strdup(token);
                            v.x = (float)atof(strtok(token, "/"));
                            if (strstr(token2, "//"))
                                v.z = (float)atof(strtok(NULL, "/"));
                            else {
                                v.y = (float)atof(strtok(NULL, "/"));
                                v.z = (float)atof(strtok(NULL, "\0"));
                            }
                            f.verts = realloc(f.verts, ++f.vertc * sizeof(VEC4));
                            f.verts[f.vertc - 1] = v;
                        }
                        obj.faces = realloc(model.faces, ++model.facec * sizeof(FACE));
                        obj.faces[obj.facec - 1] = f;
                    }
                    else
                        puts(buffer);
                }
                i = 0;
            } else {
                fclose(file);
                break;
            }
        }
        fclose(file);
    }
    free(buffer);
    return obj;
}

void sfd_free_obj(OBJ *obj) {
    free(obj->name);
    free(obj->texs);
    free(obj->faces);
    free(obj->norms);
    free(obj);
}
