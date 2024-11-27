# author: dpezdirc

from pathlib import Path

filename = "voicebank_table.h"

base_path = Path(__file__).parent
in_path = base_path / "../../../include/tables/sfx"
out_path = base_path / "../../../include/tables/sfx/strings"
in_path = in_path.resolve()
out_path = out_path.resolve()
out_path.mkdir(exist_ok=True)

sfx_common_prefix = " NA_" # start of the sfx identifier

def create_sfx_strings_file(infile, outfile):
    bank_prefix = ""  # EN, EV, etc.
    sfx_names = []

    # extract sfx names from infile
    with open(infile) as file:
        file.seek(0)
        lines = file.readlines()

        for line in lines:
            if sfx_common_prefix not in line:
                continue

            i_sfx_name_start = line.find(sfx_common_prefix) + 1
            i_sfx_name_end = line[i_sfx_name_start:].find(",") + i_sfx_name_start
            sfx_name = line[i_sfx_name_start:i_sfx_name_end]

            # strip off the prefix (NA_SE_)
            sfx_name = sfx_name[sfx_name.find("_", sfx_name.find("_") + 1) + 1:]

            # hack: some identifiers are missing the bank prefix - fix those here
            if bank_prefix == "":
                bank_prefix = sfx_name[0:2]
            if sfx_name[0:2] != bank_prefix:
                sfx_name = bank_prefix + "_" + sfx_name

            sfx_names.append(sfx_name)

    # write sfx names to outfile
    with open(outfile, "w") as file:
        for i_line, line in enumerate(sfx_names):
            file.write("\"" + sfx_names[i_line] + "\"")

            if i_line == (len(sfx_names) - 1):
                file.write("\n")
            else:
                file.write(",\n")


for in_file in in_path.iterdir():
    if not in_file.is_file():
        continue
        
    out_file_name = in_file.name
    i_underscore = str(out_file_name).find("_")
    if i_underscore > -1:
        out_file_name = Path(str(out_file_name)[:i_underscore] + "_strings.h")
        
    out_file = out_path / out_file_name
    
    create_sfx_strings_file(in_file, out_file)
    
    print(out_file)
