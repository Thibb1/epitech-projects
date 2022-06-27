#!/bin/bash
grep -e "theo1" -e "steven1" -e "arnaud1" -e "pierre-jean" | sed -e 's/theo1/Wile E. Coyote/' -e 's/steven1/Daffy Duck/' -e 's/arnaud1/Porky Pig/' -e 's/pierre-jean/Marvin the Martian/'