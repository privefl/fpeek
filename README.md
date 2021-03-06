
<!-- README.md is generated from README.Rmd. Please edit that file -->

<p align="center">

<img width="15%" src="http://www.ardata.fr/images/fpeek.svg">

</p>

## Motivation

The first motivation to write that package is that many people who need
to import text files with R don’t use `head`, `tail` and `wc -l`
commands. I noticed few use cases :

  - R is installed on a Windows machine but not Rtools (i.e. in
    corporate environments).
  - Users are unwilling to use command line, simply because there are
    not used to.
  - R is in a `Chroot Jail` and these commands are not avalaible to the
    user.

and I think these are great tools to use when importing text files.
Having a package avalaible for that should make these tools easier to
use for these users.

## fpeek

The goal of fpeek is to help importation of text files from R.

When a text file has unknown characteristics, beeing able to have a
glance at it helps to get those:

  - Use function `wc_l()` to count lines contained in a file.
  - Functions `file_head_show()` and `file_tail_show()` will display
    first and last lines of the file. Function `file_less` is
    reproducing a basic `less` usage (available only in interactive
    mode).

Sometimes encoding is an issue when files generated on a “Windows”
machine has to be used on a “Linux” machine. Function `file_iconv` will
converts file content in one encoding to another encoding.

## Installation

``` r
devtools::install_github("davidgohel/fpeek")
```

## Example

First download an example file, the file is containing lot of times
series about power system and has lot of lines.

``` r
library(fpeek)
power_file <- "singleindex.csv"
if( !file.exists(power_file))
  download.file(
    "https://data.open-power-system-data.org/time_series/2018-03-13/time_series_15min_singleindex.csv", 
    destfile = power_file)
```

### Counting number of lines:

Using `wc -l`

``` r
system(sprintf("wc -l %s", power_file), intern = TRUE)
#> [1] "  420773 singleindex.csv"
```

Using `wc_l()`

``` r
wc_l(power_file)
#> [1] 420773
```

### Show first and last lines of a file

The first lines can be printed in the console with function
`file_head_show()`.

``` r
file_head_show(power_file, n = 4)
#> utc_timestamp,cet_cest_timestamp,AT_load_entsoe_transparency,AT_solar_generation_actual,AT_wind_onshore_generation_actual,DE_load_entsoe_transparency,DE_solar_capacity,DE_solar_generation_actual,DE_solar_profile,DE_wind_capacity,DE_wind_generation_actual,DE_wind_profile,DE_wind_offshore_capacity,DE_wind_offshore_generation_actual,DE_wind_offshore_profile,DE_wind_onshore_capacity,DE_wind_onshore_generation_actual,DE_wind_onshore_profile,DE_50hertz_load_entsoe_transparency,DE_50hertz_solar_generation_actual,DE_50hertz_solar_generation_forecast,DE_50hertz_wind_generation_actual,DE_50hertz_wind_generation_forecast,DE_50hertz_wind_offshore_generation_actual,DE_50hertz_wind_offshore_generation_forecast,DE_50hertz_wind_onshore_generation_actual,DE_50hertz_wind_onshore_generation_forecast,DE_AT_LU_load_entsoe_transparency,DE_AT_LU_solar_generation_actual,DE_AT_LU_wind_offshore_generation_actual,DE_AT_LU_wind_onshore_generation_actual,DE_amprion_load_entsoe_transparency,DE_amprion_solar_generation_actual,DE_amprion_solar_generation_forecast,DE_amprion_wind_generation_actual,DE_amprion_wind_generation_forecast,DE_amprion_wind_onshore_generation_actual,DE_tennet_load_entsoe_transparency,DE_tennet_solar_generation_actual,DE_tennet_solar_generation_forecast,DE_tennet_wind_generation_actual,DE_tennet_wind_generation_forecast,DE_tennet_wind_offshore_generation_actual,DE_tennet_wind_onshore_generation_actual,DE_transnetbw_load_entsoe_transparency,DE_transnetbw_solar_generation_actual,DE_transnetbw_solar_generation_forecast,DE_transnetbw_wind_generation_actual,DE_transnetbw_wind_generation_forecast,DE_transnetbw_wind_onshore_generation_actual,HU_load_entsoe_transparency,HU_wind_onshore_generation_actual,LU_load_entsoe_transparency,NL_load_entsoe_transparency,NL_solar_generation_actual,NL_wind_offshore_generation_actual,NL_wind_onshore_generation_actual,interpolated_values
#> 2005-12-31T23:00:00Z,2006-01-01T00:00:00+0100,,,,,2028.0000,,,,,,,,,16394.0000,,,,,,2013.0000,1366.0000,,,,,,,,,,,,,,,,,,1705.0000,1864.0000,0.0000,1705.0000,,,,,,,,,,,,,,
#> 2005-12-31T23:15:00Z,2006-01-01T00:15:00+0100,,,,,2028.0000,,,,,,,,,16394.0000,,,,,,2053.0000,1366.0000,,,,,,,,,,,,,,,,,,1739.0000,1864.0000,0.0000,1739.0000,,,,,,,,,,,,,,
#> 2005-12-31T23:30:00Z,2006-01-01T00:30:00+0100,,,,,2028.0000,,,,,,,,,16394.0000,,,,,,2188.0000,1366.0000,,,,,,,,,,,,,,,,,,1700.0000,1864.0000,0.0000,1700.0000,,,,,,,,,,,,,,
```

`file_head_char()` is also provided to get the first lines as a
character vector.

``` r
file_head_char(power_file, n = 4)
#> [1] "utc_timestamp,cet_cest_timestamp,AT_load_entsoe_transparency,AT_solar_generation_actual,AT_wind_onshore_generation_actual,DE_load_entsoe_transparency,DE_solar_capacity,DE_solar_generation_actual,DE_solar_profile,DE_wind_capacity,DE_wind_generation_actual,DE_wind_profile,DE_wind_offshore_capacity,DE_wind_offshore_generation_actual,DE_wind_offshore_profile,DE_wind_onshore_capacity,DE_wind_onshore_generation_actual,DE_wind_onshore_profile,DE_50hertz_load_entsoe_transparency,DE_50hertz_solar_generation_actual,DE_50hertz_solar_generation_forecast,DE_50hertz_wind_generation_actual,DE_50hertz_wind_generation_forecast,DE_50hertz_wind_offshore_generation_actual,DE_50hertz_wind_offshore_generation_forecast,DE_50hertz_wind_onshore_generation_actual,DE_50hertz_wind_onshore_generation_forecast,DE_AT_LU_load_entsoe_transparency,DE_AT_LU_solar_generation_actual,DE_AT_LU_wind_offshore_generation_actual,DE_AT_LU_wind_onshore_generation_actual,DE_amprion_load_entsoe_transparency,DE_amprion_solar_generation_actual,DE_amprion_solar_generation_forecast,DE_amprion_wind_generation_actual,DE_amprion_wind_generation_forecast,DE_amprion_wind_onshore_generation_actual,DE_tennet_load_entsoe_transparency,DE_tennet_solar_generation_actual,DE_tennet_solar_generation_forecast,DE_tennet_wind_generation_actual,DE_tennet_wind_generation_forecast,DE_tennet_wind_offshore_generation_actual,DE_tennet_wind_onshore_generation_actual,DE_transnetbw_load_entsoe_transparency,DE_transnetbw_solar_generation_actual,DE_transnetbw_solar_generation_forecast,DE_transnetbw_wind_generation_actual,DE_transnetbw_wind_generation_forecast,DE_transnetbw_wind_onshore_generation_actual,HU_load_entsoe_transparency,HU_wind_onshore_generation_actual,LU_load_entsoe_transparency,NL_load_entsoe_transparency,NL_solar_generation_actual,NL_wind_offshore_generation_actual,NL_wind_onshore_generation_actual,interpolated_values"
#> [2] "2005-12-31T23:00:00Z,2006-01-01T00:00:00+0100,,,,,2028.0000,,,,,,,,,16394.0000,,,,,,2013.0000,1366.0000,,,,,,,,,,,,,,,,,,1705.0000,1864.0000,0.0000,1705.0000,,,,,,,,,,,,,,"                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    
#> [3] "2005-12-31T23:15:00Z,2006-01-01T00:15:00+0100,,,,,2028.0000,,,,,,,,,16394.0000,,,,,,2053.0000,1366.0000,,,,,,,,,,,,,,,,,,1739.0000,1864.0000,0.0000,1739.0000,,,,,,,,,,,,,,"                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    
#> [4] "2005-12-31T23:30:00Z,2006-01-01T00:30:00+0100,,,,,2028.0000,,,,,,,,,16394.0000,,,,,,2188.0000,1366.0000,,,,,,,,,,,,,,,,,,1700.0000,1864.0000,0.0000,1700.0000,,,,,,,,,,,,,,"
```

The last lines can be printed in the console with function
`file_tail_show()`.

``` r
file_tail_show(power_file, n = 4)
#> 2017-12-31T23:00:00Z,2018-01-01T00:00:00+0100,5657.6000,0.0000,922.5770,44607.9100,41951.0000,0.0000,0.0000,55790.0000,30955.0000,0.5548,5323.0000,2973.0000,0.5585,50467.0000,27982.0000,0.5545,6476.3300,0.0000,0.0000,10230.6900,9979.4540,186.7680,83.5990,10043.9220,9895.8550,50769.3400,0.0000,2972.8500,28860.5200,17349.8600,0.0000,0.0000,6957.0000,6757.0000,6957.0000,15817.9100,0.0000,0.0000,12679.0000,13097.0000,2786.0000,9893.0000,4963.8100,0.0000,0.0000,1088.0000,1016.0000,1088.0000,4028.8900,78.4900,503.8300,9956.0300,0.0000,849.6100,2654.9400,
#> 2017-12-31T23:15:00Z,2018-01-01T00:15:00+0100,5597.6000,0.0000,931.9630,43777.3000,41951.0000,0.0000,0.0000,55790.0000,31608.0000,0.5666,5323.0000,2991.0000,0.5619,50467.0000,28617.0000,0.5671,6415.8600,0.0000,0.0000,10400.4320,9947.9450,203.9830,82.7620,10196.4490,9865.1830,49844.1800,0.0000,2990.8400,29549.0400,16857.5200,0.0000,0.0000,7046.0000,6850.0000,7046.0000,15618.8700,0.0000,0.0000,13057.0000,13284.0000,2787.0000,10270.0000,4885.0500,0.0000,0.0000,1105.0000,1025.0000,1105.0000,4002.3600,82.5400,469.2800,9856.0100,0.0000,852.6100,2738.7900,
#> 2017-12-31T23:30:00Z,2018-01-01T00:30:00+0100,5596.8000,0.0000,922.9650,43532.3000,41951.0000,0.0000,0.0000,55790.0000,31874.0000,0.5713,5323.0000,2921.0000,0.5487,50467.0000,28953.0000,0.5737,6299.5400,0.0000,0.0000,10393.0210,9918.7440,197.7470,82.0160,10195.2740,9836.7280,49597.5400,0.0000,2920.5600,29908.3100,16715.4600,0.0000,0.0000,7132.0000,6946.0000,7132.0000,15633.5900,0.0000,0.0000,13266.0000,13477.0000,2723.0000,10543.0000,4883.7100,0.0000,0.0000,1083.0000,1033.0000,1083.0000,3965.5900,93.1400,468.4400,9727.4900,0.0000,855.3900,2742.4000,
#> 2017-12-31T23:45:00Z,2018-01-01T00:45:00+0100,5665.6000,0.0000,881.0160,43293.6300,41951.0000,0.0000,0.0000,55790.0000,31873.0000,0.5713,5323.0000,2785.0000,0.5232,50467.0000,29088.0000,0.5764,6275.1900,0.0000,0.0000,10556.6970,9893.5240,189.9090,81.2330,10366.7880,9812.2910,49433.8600,0.0000,2785.0400,30080.3900,16617.8000,0.0000,0.0000,7111.0000,6993.0000,7111.0000,15525.7200,0.0000,0.0000,13139.0000,13652.0000,2595.0000,10544.0000,4874.9200,0.0000,0.0000,1066.0000,1042.0000,1066.0000,3945.0800,105.9100,474.6300,9742.8100,0.0000,861.7700,2749.5000,
```

`file_tail_char()` is also provided to get the last lines as a character
vector.

``` r
file_tail_char(power_file, n = 4)
#> [1] "2017-12-31T23:00:00Z,2018-01-01T00:00:00+0100,5657.6000,0.0000,922.5770,44607.9100,41951.0000,0.0000,0.0000,55790.0000,30955.0000,0.5548,5323.0000,2973.0000,0.5585,50467.0000,27982.0000,0.5545,6476.3300,0.0000,0.0000,10230.6900,9979.4540,186.7680,83.5990,10043.9220,9895.8550,50769.3400,0.0000,2972.8500,28860.5200,17349.8600,0.0000,0.0000,6957.0000,6757.0000,6957.0000,15817.9100,0.0000,0.0000,12679.0000,13097.0000,2786.0000,9893.0000,4963.8100,0.0000,0.0000,1088.0000,1016.0000,1088.0000,4028.8900,78.4900,503.8300,9956.0300,0.0000,849.6100,2654.9400,"  
#> [2] "2017-12-31T23:15:00Z,2018-01-01T00:15:00+0100,5597.6000,0.0000,931.9630,43777.3000,41951.0000,0.0000,0.0000,55790.0000,31608.0000,0.5666,5323.0000,2991.0000,0.5619,50467.0000,28617.0000,0.5671,6415.8600,0.0000,0.0000,10400.4320,9947.9450,203.9830,82.7620,10196.4490,9865.1830,49844.1800,0.0000,2990.8400,29549.0400,16857.5200,0.0000,0.0000,7046.0000,6850.0000,7046.0000,15618.8700,0.0000,0.0000,13057.0000,13284.0000,2787.0000,10270.0000,4885.0500,0.0000,0.0000,1105.0000,1025.0000,1105.0000,4002.3600,82.5400,469.2800,9856.0100,0.0000,852.6100,2738.7900," 
#> [3] "2017-12-31T23:30:00Z,2018-01-01T00:30:00+0100,5596.8000,0.0000,922.9650,43532.3000,41951.0000,0.0000,0.0000,55790.0000,31874.0000,0.5713,5323.0000,2921.0000,0.5487,50467.0000,28953.0000,0.5737,6299.5400,0.0000,0.0000,10393.0210,9918.7440,197.7470,82.0160,10195.2740,9836.7280,49597.5400,0.0000,2920.5600,29908.3100,16715.4600,0.0000,0.0000,7132.0000,6946.0000,7132.0000,15633.5900,0.0000,0.0000,13266.0000,13477.0000,2723.0000,10543.0000,4883.7100,0.0000,0.0000,1083.0000,1033.0000,1083.0000,3965.5900,93.1400,468.4400,9727.4900,0.0000,855.3900,2742.4000," 
#> [4] "2017-12-31T23:45:00Z,2018-01-01T00:45:00+0100,5665.6000,0.0000,881.0160,43293.6300,41951.0000,0.0000,0.0000,55790.0000,31873.0000,0.5713,5323.0000,2785.0000,0.5232,50467.0000,29088.0000,0.5764,6275.1900,0.0000,0.0000,10556.6970,9893.5240,189.9090,81.2330,10366.7880,9812.2910,49433.8600,0.0000,2785.0400,30080.3900,16617.8000,0.0000,0.0000,7111.0000,6993.0000,7111.0000,15525.7200,0.0000,0.0000,13139.0000,13652.0000,2595.0000,10544.0000,4874.9200,0.0000,0.0000,1066.0000,1042.0000,1066.0000,3945.0800,105.9100,474.6300,9742.8100,0.0000,861.7700,2749.5000,"
```

### File reencoding

``` r
la_cigale <- system.file(package = "fpeek", "datafiles", 
  "cigale-ISO-8859-1.txt")
file_head_char(la_cigale, n = 4)
#> [1] "La Cigale et la Fourmi"     ""                          
#> [3] "La Cigale, ayant chant\xe9" "Tout l'\xe9t\xe9,"

file_iconv_show(la_cigale, from = "WINDOWS-1252", to = "UTF-8")
#> La Cigale et la Fourmi
#> 
#> La Cigale, ayant chanté
#> Tout l'été,
#> Se trouva fort dépourvue
#> Quand la bise fut venue :
#> Pas un seul petit morceau
#> De mouche ou de vermisseau.
#> Elle alla crier famine
#> Chez la Fourmi sa voisine,
#> La priant de lui prêter
#> Quelque grain pour subsister
#> Jusqu'à la saison nouvelle.
#> Je vous paierai, lui dit-elle,
#> Avant l'Oût, foi d'animal,
#> Intérêt et principal. 
#> La Fourmi n'est pas prêteuse :
#> C'est là son moindre défaut.
#> Que faisiez-vous au temps chaud ?
#> Dit-elle à cette emprunteuse.
#> Nuit et jour à tout venant
#> Je chantais, ne vous déplaise.
#> Vous chantiez ? j'en suis fort aise.
#> Eh bien! dansez maintenant.
```

Function `file_iconv_show()` is converting the content of the file and
print the result in the console. Use `file_iconv_write()` to create a
new reencoded file:

``` r
file_utf8 <- tempfile()
file_iconv_write(path = la_cigale, newfile = file_utf8, 
  from = "WINDOWS-1252", to = "UTF-8")
#> [1] "/var/folders/51/6jygptvs3bb4njv0t6x7br900000gn/T//RtmpLXtMdk/file4c07a3e3ca1"
```

## Comparing speed with other methods:

> function `wc_l`

``` r
library(microbenchmark)

benchmark <- microbenchmark(times = 20, 
  "fpeek::wc_l" = { wc_l(power_file) },
  "R.utils::countLines" = { R.utils::countLines(power_file) }, 
  "wc command" = { system(sprintf("wc -l %s", power_file), intern = TRUE) }
  )

benchmark
#> Unit: milliseconds
#>                 expr       min        lq      mean    median        uq
#>          fpeek::wc_l  282.4091  284.3698  291.4240  288.1993  299.0682
#>  R.utils::countLines 2913.9760 2974.8871 3032.2352 3014.4298 3074.6154
#>           wc command  106.2395  108.0034  110.9642  110.2417  113.2166
#>        max neval
#>   308.2205    20
#>  3254.8114    20
#>   121.3721    20
```

> function `file_head_show`

``` r
library(microbenchmark)
benchmark <- microbenchmark(times = 20, 
  "fpeek::file_head_show" = { file_head_show(power_file, n = 5) },
  "base::readLines" = { print(readLines(power_file, n = 5)) }, 
  "head command" = { print(system(sprintf("head -n 5 %s", power_file), intern = TRUE)) }
  )
```

``` r
benchmark
#> Unit: microseconds
#>                   expr      min       lq      mean    median        uq
#>  fpeek::file_head_show   50.023   61.509   74.7807   68.7555   83.9775
#>        base::readLines 1195.054 1207.669 1242.1771 1231.0525 1247.8950
#>           head command 4636.444 4757.171 5141.6427 4942.2470 5218.3600
#>       max neval
#>   127.631    20
#>  1432.014    20
#>  7539.492    20
```
