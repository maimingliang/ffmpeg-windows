/*
 * linear least squares model
 *
 * Copyright (c) 2006 Michael Niedermayer <michaelni@gmx.at>
 *
 * This file is part of FFmpeg.
 *
 * FFmpeg is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * FFmpeg is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with FFmpeg; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

//****************************************************************************//
//libavutil\lls.h
//	线性最小二乘法模型
//学习的地方：
//1.不明白什么是线性最小二乘法模型？
//2.搞不懂这个到底有什么用啊？
//附录：
//1.
//****************************************************************************//


#ifndef AVUTIL_LLS_H
#define AVUTIL_LLS_H
#include "libavutil/attributes.h"

#define MAX_VARS 32

//FIXME avoid direct access to LLSModel from outside

/**
 * Linear least squares model.
 */
typedef struct LLSModel
{
    double covariance[MAX_VARS+1][MAX_VARS+1];
    double coeff[MAX_VARS][MAX_VARS];
    double variance[MAX_VARS];
    int indep_count;
} LLSModel;

FFMPEGLIB_API void av_init_lls(LLSModel *m, int indep_count);
FFMPEGLIB_API void av_update_lls(LLSModel *m, double *param, double decay);
FFMPEGLIB_API void av_solve_lls(LLSModel *m, double threshold, int min_order);
FFMPEGLIB_API double av_evaluate_lls(LLSModel *m, double *param, int order);

#endif /* AVUTIL_LLS_H */
