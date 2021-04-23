* Nous Voudrions adapter notre code à celui de verificarlo, pour ce faire, nous considerons que verificarlo comme un template. la première étape serait de considérer les fonctions : 


- interflop_add_float()

- interflop_sub_float()

- interflop_mul_flot

et :


- interflop_add_double()

- interflop_sub_double()

- interflop_mul_double()

leurs implémentations sera remplacé par linplémentation des fonctions 


- fixed32_add()

- fixed32_sub()

- fixed32_mu()

et par : 

- fixed64_add()

- fixed64_sub()

- fixed64_mul()


La difficulter c'est qu'il n'est pas sûr que le compilateur prenne en compte un type _int128_t.
il se trouve dans les "src".


* Un algorithme pour gérer la division a été proposer dans les "resources".
