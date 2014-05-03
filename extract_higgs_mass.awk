BEGIN {
   in_mass_block=0
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
      print $2
   }
}
