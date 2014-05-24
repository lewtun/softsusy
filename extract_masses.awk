BEGIN {
   in_mass_block=0
   mh=0
   mstop1=0
   mstop2=0
}

{
  if ($0 ~ /^ *#/)
    next

   if (tolower($0) ~ /block  *mass */) {
      in_mass_block=1
   } else if (tolower($0) ~ /block *[a-z]*/) {
      in_mass_block=0
   }

   if (in_mass_block == 1 && $1 == 25) {
      mh=$2
   }
   if (in_mass_block == 1 && $1 == 1000006) {
      mstop1=$2
   }
   if (in_mass_block == 1 && $1 == 2000006) {
      mstop2=$2
   }
}
END {
   print mh " " mstop1 " " mstop2
}
