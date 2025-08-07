rule Detect_MZ_Header {
    meta:
        description = "Detects MZ header in executable files"
        author = "onhexgroup"
        date = "2025-04-30"
    strings:
        $mz_header = "MZ"
    condition:
        $mz_header at 0
}