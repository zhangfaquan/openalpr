/*
 * Copyright (c) 2014 New Designs Unlimited, LLC
 * Opensource Automated License Plate Recognition [http://www.openalpr.com]
 *
 * This file is part of OpenAlpr.
 *
 * OpenAlpr is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License
 * version 3 as published by the Free Software Foundation
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
*/

// This class finds lines of text given an array of contours

#ifndef OPENALPR_LINEFINDER_H
#define	OPENALPR_LINEFINDER_H

#include "opencv2/imgproc/imgproc.hpp"
#include "textcontours.h"
#include "textline.h"
#include "pipeline_data.h"


class LineFinder {
public:
  LineFinder(PipelineData* pipeline_data);
  virtual ~LineFinder();
  
  std::vector<TextLine> findLines(cv::Mat image, const TextContours contours);
private:
  PipelineData* pipeline_data;
          
  std::vector<cv::Rect> getBoundingBoxes(const TextContours contours);
  std::vector<cv::Point> getCharTops(std::vector<cv::Rect> boxes);
  std::vector<cv::Point> getCharBottoms(std::vector<cv::Rect> boxes);
  
  std::vector<cv::Point> getBestLine(const TextContours contours, std::vector<cv::Point> tops, std::vector<cv::Point> bottoms);
};

#endif	/* OPENALPR_LINEFINDER_H */

