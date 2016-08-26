<table class = "table table-condensed">
	<tr>
		<th class="text-center">Transaction</th>
		<th class="text-center">Stock</th>
		<th class="text-center">Shares</th>
		<th class="text-center">Price</th>
	    <th class="text-center">Date and Time</th>
	</tr>
 
	<?php foreach ($positions as $position): ?>
		<tr>
	    <td><?= $position["transaction"] ?></td>
		<td><?= $position["symbol"] ?></td> 
		<td><?= $position["shares"] ?></td> 
		<td><?= $position["price"] ?></td> 
		<td><?= $position["timestamp"] ?></td>
		</tr>
		<br>
	<?php endforeach ?>
 
</table>