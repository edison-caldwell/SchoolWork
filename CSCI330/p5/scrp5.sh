#!/bin/bash

#cp ../files/* .
c++ *.cpp -c &>compile.out
c++ *.o -o p5.exe &> link.out

cp dice_a.in dice.in
./p5.exe<run_a.in> run_a.out
mv combat.out combat_a.out
mv zimmer.out zimmer_a.out
diff z_run_a.out run_a.out>diff_run_a.out
diff z_a.out zimmer_a.out>diff_a.out
diff z_combat_a.out combat_a.out>diff_combat_a.out

cp dice_b.in dice.in
./p5.exe<run_b.in> run_b.out
mv combat.out combat_b.out
mv zimmer.out zimmer_b.out
diff z_run_b.out run_b.out>diff_run_b.out
diff z_b.out zimmer_b.out>diff_b.out
diff z_combat_b.out combat_b.out>diff_combat_b.out

cp dice_c.in dice.in
./p5.exe<run_c.in> run_c.out
mv combat.out combat_c.out
mv zimmer.out zimmer_c.out
diff z_run_c.out run_c.out>diff_run_c.out
diff z_c.out zimmer_c.out>diff_c.out
diff z_combat_c.out combat_c.out>diff_combat_c.out


ls -l diff*.out



