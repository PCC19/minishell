set number " numeros de linha
" set rnu "relative numbers
color slate
syntax on
set hlsearch
nnoremap <silent> [b :bprevious<CR>
nnoremap <silent> ]b :bnext<CR>
nnoremap <silent> [B :bfirst<CR>
nnoremap <silent> ]B :blast<CR>
set noerrorbells visualbell t_vb=
set wildmenu
"set expandtab       " replace tabs with spaces
set autoindent      " copy indent when starting a new line
set tabstop=4
set softtabstop=4
set shiftwidth=4
:abbr std #include<stdio.h>
set colorcolumn=81
map <S-Left> :tabp<cr>
map <S-Right> :tabn<cr>
map <S-Tab> :tabnew<cr>
map <C-a> gg<S-v><S-g>
map :bb :buffers<cr>
set ruler
set cursorline
set suffixesadd+=.c
map	gf <C-w>gf
